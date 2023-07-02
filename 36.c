/*
wait command
gcc -o h 36.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int i = 10;

int main() {
    int pid = fork();
    if (pid == 0) {
        printf("initial value of i %d \n ", i);
        i += 10;
        printf("value of i %d \n ", i);
        printf("child terminated \n");
    } else {
        wait(0);
        printf("value of i in parent process %d", i); 
    }

    return 0;
}
