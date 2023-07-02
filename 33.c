#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
SLEEP COMMAND
gcc -o h 33.c
./h
*/
int main(void)
{
    int id= fork();
    if(id==1)
    {
        printf("Can not create file");
        exit(1);

    }else if(id==0)
    {
        sleep(3);
        printf("Child process!");
    }else{
        printf("Parent Process!");
        exit(1);
    }
}