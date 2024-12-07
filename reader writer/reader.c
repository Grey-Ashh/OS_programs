#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>

int main()
{
    int shmid;
    shmid=shmget((key_t)2366,1024,0666);
    printf("the id is %d\n",shmid);
    void *shm=shmat(shmid,NULL,0);
    printf("the process is attached at %p\n",shm);
    printf("The shared item is %s",(char*)shm);
}
