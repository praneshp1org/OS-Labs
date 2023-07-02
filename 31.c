#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int id;
    id = fork();
    if(id<0)
    {
        printf("Cannot create file!\n");
        exit(-1);

    }
    if(id==0)
    {
        printf("Child process!\n");
    }else
    {
        printf("Parent process!\n");
    }

    return 0;


}

