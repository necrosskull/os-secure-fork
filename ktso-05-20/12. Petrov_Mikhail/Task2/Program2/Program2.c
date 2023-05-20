#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int pipefd1[2];
    int pipefd2[2];
    pid_t pid;
    char buf[32];
    char* ParentMsg = "From Parent";
    char* ChildMsg = "From Child";

    if (pipe(pipefd1) == -1)
    {
        perror("pipe");
        return -1;
    }

    if (pipe(pipefd2) == -1)
    {
        close(pipefd1[0]);
        close(pipefd1[1]);
        perror("pipe");
        return -1;
    }

    pid = fork();

    if (pid < 0) // Error
    {
        perror("fork");
        close(pipefd1[0]);
        close(pipefd1[1]);
        close(pipefd2[0]);
        close(pipefd2[1]);
        return -1;
    }

    if (pid == 0) // Child
    {
        close(pipefd1[1]);
        while (read(pipefd1[0], &buf, sizeof(buf)) > 0);
        puts(buf);
        close(pipefd1[0]);

        close(pipefd2[0]);
        write(pipefd2[1], ChildMsg, strlen(ChildMsg) + 1);
        close(pipefd2[1]);
    }

    if (pid > 0) // Parent
    {
        close(pipefd1[0]);
        write(pipefd1[1], ParentMsg, strlen(ParentMsg) + 1);
        close(pipefd1[1]);

        close(pipefd2[1]);
        while (read(pipefd2[0], &buf, sizeof(buf)) > 0);
        puts(buf);

        wait(NULL);
        exit(EXIT_SUCCESS);
    }
}
