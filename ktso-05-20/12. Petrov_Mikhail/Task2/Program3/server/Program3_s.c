#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#define PIPE_NAME "/tmp/my_named_pipe"
#define BUFSIZE 200

int fd = 0;

void CtrlCHandler(int dummy)
{
    if (fd != 0)
    {
        close(fd);
        remove(PIPE_NAME);
        puts("\nPipe closed and removed");
    }
    exit(EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
    char buf[BUFSIZE];

    signal(SIGINT, CtrlCHandler);

    if (mkfifo(PIPE_NAME, 0777))
    {
        if (errno == EEXIST)
        {
            remove(PIPE_NAME);
            if (mkfifo(PIPE_NAME, 0777))
            {
                perror("mkfifo");
                return 1;
            }
        }
        else
        {
            perror("mkfifo");
            return 1;
        }
    }

    printf("%s is created\n", PIPE_NAME);

    if ((fd = open(PIPE_NAME, O_RDONLY)) <= 0)
    {
        perror("open error:");
        return 1;
    }

    printf("%s is opened for reading\n", PIPE_NAME);

    do
    {
        memset(buf, '\0', BUFSIZE);
        read(fd, buf, BUFSIZE - 1);
        printf("Incoming message: %s\n", buf);
        buf[0] = toupper(buf[0]);
        printf("Outgooing message: %s\n", buf);
        printf("%s is closed and reopened for writing\n", PIPE_NAME);
        close(fd);
        fd = open(PIPE_NAME, O_WRONLY);
        write(fd, buf, BUFSIZE - 1);
        printf("%s is closed and reopened for reading\n", PIPE_NAME);
        close(fd);
        fd = open(PIPE_NAME, O_RDONLY);
    } while (1);
}