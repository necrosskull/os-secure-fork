#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>

#define PIPE_NAME "/tmp/my_named_pipe"
#define BUFSIZE 200

int fd = 0;

void CtrlCHandler(int dummy)
{
    if (fd != 0)
    {
        close(fd);
        puts("\nPipe closed");
    }
    exit(EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
    char buf[BUFSIZE];

    signal(SIGINT, CtrlCHandler);

    if ((fd = open(PIPE_NAME, O_WRONLY)) <= 0)
    {
        perror("open error:");
        return 1;
    }

    printf("%s is opened for writing\n", PIPE_NAME);

    do
    {
        memset(buf, '\0', BUFSIZE);
        scanf("%s", buf);
        printf("Incoming message: %s\n", buf);
        write(fd, buf, BUFSIZE - 1);
        printf("%s is closed and reopened for reading\n", PIPE_NAME);
        close(fd);
        fd = open(PIPE_NAME, O_RDONLY);
        read(fd, buf, BUFSIZE - 1);
        printf("Outgooing message: %s\n", buf);
        printf("%s is closed and reopened for reading\n", PIPE_NAME);
        close(fd);
        fd = open(PIPE_NAME, O_WRONLY);
    } while (1);
}