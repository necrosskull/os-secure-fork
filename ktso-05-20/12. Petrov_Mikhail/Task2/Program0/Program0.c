#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    putenv("NEWVAR=PARENTVAL");

    pid_t pid = fork();

    if (pid < 0) // Error
    {
        perror("fork");
        return -1;
    }

    if (pid == 0) // Child
    {
        char* envvar = getenv("NEWVAR");
        printf("Envvar NEWVAR = %s\n", envvar);
    }

    return 0;
}