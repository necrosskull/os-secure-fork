#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <ctype.h>
#include <sys/types.h>
#include "../msg.h"

#define PORT 60000

int lfd = 0;

void CtrlCHandler(int dummy)
{
    if (lfd != 0 )
    {
        close(lfd);
    }
    exit(EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
    int fd = 0;
    struct sockaddr_in sa;
    int len;
    unsigned int buf;
    FILE *pPipe;
    char answer[256];
    char tmp;
    int cnt;

    memset(answer, '\0', sizeof(answer));

    signal(SIGINT, CtrlCHandler);

    lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd < 0)
    {
        perror("socket");
        return 1;
    }

    int true = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &true, sizeof(int));

    memset(&sa, '\0', sizeof(sa));

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = htonl(INADDR_ANY);
    sa.sin_port = htons(PORT);

    if(bind(lfd, (struct sockaddr*)&sa, sizeof(sa)))
    {
        perror("bind");
        return 1;
    }

    puts("Socket opened.");

    if(listen(lfd, 1))
    {
        perror("listen");
        return 1;
    }

    fd = accept(lfd, (struct sockaddr*)NULL, NULL);

    while(1)
    {
        len = read(fd, &buf, 1);

        if (len > 0 && buf > 0)
        {
            PMESSAGE pmsg = malloc(buf);
            pmsg->len = (unsigned char)buf;

            len = read(fd, &buf, 1);
            pmsg->type = buf;

            if (pmsg->type != 1)
            {
                puts("Incorrect packet.");
                break;
            }

            len = read(fd, (char*)&pmsg->body, pmsg->len - 1);

//            printf("%u %u %s\n", pmsg->len, pmsg->type, (char*)&pmsg->body);
            printf("Command received: %s\n", (char*)&pmsg->body);

            if (strcmp((char*)&pmsg->body, "exit") == 0)
            {
                puts("Exit command.");
                break;
            }

            pPipe = popen((char*)&pmsg->body, "r");
            free(pmsg);

            if(pPipe == 0)
            {
                perror("pipe");
                break;
            }

            cnt = 0;
            while(fread(&tmp, 1, 1, pPipe) == 1)
            {
                answer[cnt++] = tmp;

                if (cnt > 253)
                {
                    break;
                }

                if (feof(pPipe))
                {
                    break;
                }
            }

            answer[cnt] = '\0';
//            printf("%d\n%s\n", cnt, answer);

            pmsg = malloc(cnt + 2);
            pmsg->len = cnt + 2;
            pmsg->type = 0;
            strcpy((char*)&pmsg->body, answer);

//            printf("%u %u %s\n", pmsg->len, pmsg->type, (char*)&pmsg->body);
            write(fd, pmsg, pmsg->len);
            free(pmsg);
            break;
        }
        else
        {
            break;
        }
    }

    puts("Socket closed.");
    shutdown(fd, SHUT_RDWR);
    shutdown(lfd, SHUT_RDWR);
    close(fd);
    close(lfd);
    exit(EXIT_SUCCESS);
}