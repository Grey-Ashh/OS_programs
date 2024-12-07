#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void)
{
    char *arg1,*arg2,*binarypath;
    printf("Enter the path: ");
    scanf("%s",arg2);
    binarypath="bin/ls";
    arg1="-l";
    execl(binarypath,binarypath,arg1,arg2,NULL);
    return 0;   
}
