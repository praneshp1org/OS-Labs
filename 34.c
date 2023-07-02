/*
getpid() using SLEEP Command
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int pid;
    pid = fork();
    if(pid==0)
    {
        printf("\nChild Process\n");
        printf("\nChild Process id is %d ", getpid());
        printf("\nIts parent process id is %d", getppid());
        sleep(3);
        printf("\nChild process after sleep=3\n");
        printf("\nChild Process id is %d ", getpid());
        printf("\nIts parent process id is %d", getppid());
    }
    else
    {
        printf("\nParent Process!");
        sleep(10);
        printf("\nChild Process id is %d ", getpid());
        printf("\nIts parent process id is %d", getppid());
        printf("\nParent terminates!");
    }
}
