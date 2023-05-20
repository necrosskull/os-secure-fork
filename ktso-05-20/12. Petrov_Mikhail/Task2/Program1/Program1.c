#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>

pid_t pid;

void ParentHandler(int sig)
{
    puts("Parent has signal SIGUSR1 from child.");
    kill(pid, SIGUSR2);
}

void ChildHandler(int sig)
{
    puts("Child has signal SIGUSR2 from parent.");
    exit(0);
}

int main()
{
    int status;

    puts("Parent set handler SIGUSR1.");
    signal(SIGUSR1, ParentHandler);

    pid = fork();

    if (pid < 0) // Error
    {
        perror("fork");
        return -1;
    }

    if (pid == 0) // Child
    {
        puts("Child set handler SIGUSR2.");
        signal(SIGUSR2, ChildHandler);
        puts("Child send SIGUSR1 to parent.");
        kill(getppid(), SIGUSR1);
        while(1);
    }

    if (pid > 0) // Parent
    {
        puts("Parent wait child to terminate.");
        waitpid(pid, &status, 0); 
    }
}