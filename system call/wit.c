#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    if(fork()==0)
    {
        printf("child.\n");
    }
    else
    {
        printf("Parent .\n");
        wait(NULL);
        printf("terminated.\n");
    }
    printf("End.\n");
}