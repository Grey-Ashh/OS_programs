#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<dirent.h>

struct dirent *dptr;
int main(int argc ,char*arg[])
{
    char buff[100];
    DIR *drip;
    printf("Enter the directory name: ");
    scanf("%s",buff);
    drip=opendir(buff);
    if(drip==NULL)
    {
        printf("No such directory exist.");
        exit(1);
    }
    while (dptr=readdir(drip))
    {
        printf("%s\n",dptr->d_name);
    }
    closedir(drip);
}
