#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>

int main()
{
    int shmid;
    char str[100];
    shmid=shmget((key_t)2366,1024,0666|'IPS_CREAT');
    printf("the id is %d\n",shmid);
    void *shm=shmat(shmid,NULL,0);
    printf("the process is attached at %p\n",shm);

    printf("Enter the input : ");
    scanf("%s",str);
    strcpy(shm,str);

    printf("The shared item is %s",(char*)shm);
}
