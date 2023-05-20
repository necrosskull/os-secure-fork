#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

struct mesgq{
    long type;
    char text[200];
} mq;

int main()
{
    int len, msqid1;
    key_t key1 = 1000;

    if ((msqid1 = msgget(key1, 0644|IPC_CREAT)) == -1)
    {
        perror("msgget error client 1");
        exit(1);
    }

    printf("Server ready: \n");
    printf("Enter text, ^D to quit: \n");
    mq.type = 1;
    while(fgets(mq.text, sizeof(mq.text), stdin) != NULL)
    {
        len = strlen(mq.text);
        if (mq.text[len-1] == '\n')
            mq.text[len-1] = '\0';
        msgsnd(msqid1, &mq, len+1, 0);

        if (msgrcv(msqid1, &mq, sizeof(mq.text), 1, 0))
            printf("From client 1: \"%s\"\n", mq.text);        
    }
    msgctl(msqid1, IPC_RMID, NULL);
}