#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
int main()
{   
    struct stat sfile;
    stat("Grey",&sfile);
    pirntf("st_mode=%o",sfile.st_mode);
    return 0;
}