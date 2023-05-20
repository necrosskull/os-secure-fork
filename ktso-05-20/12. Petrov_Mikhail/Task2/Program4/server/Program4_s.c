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

#define PORT 60000
#define BUFSIZE 256

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
    char buf[BUFSIZE];

    signal(SIGINT, CtrlCHandler);

    lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd < 0)
    {
        perror("socket");
        return 1;
    }

    memset(&sa, '\0', sizeof(sa));
    memset(buf, '\0', sizeof(buf));

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = htonl(INADDR_ANY);
    sa.sin_port = htons(PORT);

    printf("Socket opened\n");
    bind(lfd, (struct sockaddr*)&sa, sizeof(sa));
    listen(lfd, 1);

    fd = accept(lfd, (struct sockaddr*)NULL, NULL);

    while(1)
    {
        memset(buf, '\0', BUFSIZE);
        len = read(fd, buf, BUFSIZE - 1);
        if (len > 0)
        {
            printf("Incoming message: %s\n", buf);
            buf[0] = toupper(buf[0]);
            printf("Outgooing message: %s\n", buf);
            write(fd, buf, BUFSIZE - 1);
        }
        else
        {
            close(fd);
            exit(EXIT_SUCCESS);
        }
        sleep(1);
    }
}