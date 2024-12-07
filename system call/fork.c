#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    int pid,pid1,pid2;
    pid=fork();
    if (pid==-1)
    {
        printf("Error.\n");
        exit(1);
    }
    if (pid!=0)
    {
        pid1=getpid();
        printf("Child process  %d.\n",pid1);
    }
    if (pid==0)
    {
        pid2=getpid();
        printf("Parent process  %d.\n",pid2);
    }
    
}
