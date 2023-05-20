#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>

#include "../msg.h"

#define PORT 60000

int fd = 0;

void CtrlCHandler(int dummy)
{
    if (fd != 0 )
    {
        close(fd);
    }
    exit(EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
    char addr[32];
    unsigned char buf;
    int len;
    struct sockaddr_in sa;
    char* cmd;

    if (argc < 3)
    {
        printf("Syntax: %s <IP address> <command>\n", argv[0]);
        return 0;
    }

    cmd = argv[2];

    memset(&sa, '\0', sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(PORT);

    if(inet_pton(AF_INET, argv[1], &sa.sin_addr) <= 0)
    {
        printf("inet_pton error occured\n");
        return 1;
    }

    signal(SIGINT, CtrlCHandler);

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0)
    {
        perror("socket");
        return 1;
    }

    if(connect(fd, (struct sockaddr*)&sa, sizeof(sa)) < 0)
    {
       perror("connect");
       return 1;
    }

    printf("Socket connected.\n");

    PMESSAGE pmsg;
    pmsg = malloc(sizeof(MESSAGE) + strlen(cmd));

    pmsg->len = strlen(cmd) + 3;
    pmsg->type = 1;
    strcpy((char*)&pmsg->body, cmd);

//    printf("%u %u %s\n", pmsg->len, pmsg->type, (char*)&pmsg->body);

    len = write(fd, pmsg, pmsg->len);
    free(pmsg);
 
    sleep(1);

    len = read(fd, &buf, 1);

    if (len > 0 && buf > 0)
    {
        PMESSAGE pmsg = malloc(buf);
        pmsg->len = (unsigned char)buf;

        len = read(fd, &buf, 1);
        pmsg->type = buf;

        if (pmsg->type != 0)
        {
            puts("Incorrect packet.");
            close(fd);
            exit(EXIT_SUCCESS);
        }

        len = read(fd, (char*)&pmsg->body, pmsg->len - 1);

//        printf("%u %u %s\n", pmsg->len, pmsg->type, (char*)&pmsg->body);
        printf("Command output:\n%s\n", (char*)&pmsg->body);
        free(pmsg);
    }

    shutdown(fd, SHUT_RDWR);
    close(fd);
    return 0;
}