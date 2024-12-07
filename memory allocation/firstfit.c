#include<stdio.h>

struct block
{
    int mem;
    int flag;
    int process;
}; typedef struct block bl;

int main()
{
    int m,p;
    int i,j;

    printf("Enter the no.of memloc:");
    scanf("%d",&m);

    bl me[m];

    printf("Enter the memloc:");
    for(i=0;i<m;i++)
    {
        scanf("%d",&me[i].mem);
        me[i].flag=0;
    }

    printf("Enter the no.of processes:");
    scanf("%d",&p);
    
    int pro[p];

    printf("Enter the processes:");
    for(i=0;i<p;i++)
    {
        scanf("%d",&pro[i]);
    }

    for(i=0;i<p;i++)
    {
        for(j=0;j<m;j++)
        {
            if(pro[i]<=me[j].mem && me[j].flag==0)
            {
                me[j].process=pro[i];
                me[j].flag=1;
                break;
            }
        }
    }
    printf("mem\tprosses\n");
    for(i=0;i<m;i++)
    {
        printf("%d\t%d\n",me[i].mem,me[i].process);
    }
    return 0;
}