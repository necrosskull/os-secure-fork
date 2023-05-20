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

#define HOST "127.0.0.1"
#define PORT 60000
#define BUFSIZE 256

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
    char buf[BUFSIZE];

    struct sockaddr_in sa;

    signal(SIGINT, CtrlCHandler);

    memset(buf, '\0', sizeof(buf));

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0)
    {
        perror("socket");
        return 1;
    }

    memset(&sa, '\0', sizeof(sa));

    sa.sin_family = AF_INET;
    sa.sin_port = htons(PORT);

    if(inet_pton(AF_INET, HOST, &sa.sin_addr) <= 0)
    {
        printf("inet_pton error occured\n");
        return 1;
    }

    if(connect(fd, (struct sockaddr*)&sa, sizeof(sa)) < 0)
    {
       printf("Error : Connect Failed \n");
       return 1;
    }

    printf("Socket connected\n");

    while(1)
    {
        memset(buf, '\0', BUFSIZE);
        scanf("%s", buf);
        printf("Incoming message: %s\n", buf);
        write(fd, buf, BUFSIZE - 1);
        read(fd, buf, BUFSIZE - 1);
        printf("Outgooing message: %s\n", buf);
        sleep(1);
    }
 
    return 0;
}