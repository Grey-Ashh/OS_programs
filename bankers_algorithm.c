#include<stdio.h>

int main()
{
    int i,j;
    int p,r;
    printf("Enter no of process: ");
    scanf("%d",&p);
    printf("Enter no of resorce: ");
    scanf("%d",&r);
    int alloc[p][r];
    int max[p][r];
    int need[p][r];
    int avail[r];
    printf("Enter allocation matrix: ");
    for(i=0;i<p;i++)
        for(j=0;j<r;j++)
            scanf("%d",&alloc[i][j]);
    printf("Enter max matrix: ");
    for(i=0;i<p;i++)
        for(j=0;j<r;j++)
            scanf("%d",&max[i][j]);
    printf("Enter available: ");
    for(i=0;i<r;i++)
        scanf("%d",&avail[i]);


    int index=0;
    int flag[p];
    int seq[p];
    for(i=0;i<p;i++)
        flag[i]=0;
    int fl;


    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    
    for (i=0;i<p;i++)
    {
        for (j=0;j<p;j++)
        {
            if(flag[j]==0)
            {
                fl=0;
                for(int k=0;k<r;k++)
                {
                    if(need[j][k]>avail[k])
                    {
                        fl=1;
                        break;
                    }
                }
                if(fl==0)
                {
                   seq[index++]=j; 
                   flag[j]=1;
                   for(int m=0;m<r;m++)
                        avail[m]=avail[m]+alloc[j][m];
                }
            }
        }
    }
    

    fl=1;
    for (i=0;i<p;i++)
    {
        if(flag[i]==0)
        {
            fl=0;
            break;
        }
    }   
    if(fl==1)
    {
        printf("Safe state : \n");
        for(i=0;i<p;i++)
            printf("%d ",seq[i]);
    }
    else
        printf("Deadlock\n");

    printf("\nNeed matrix:\n");
    for (i=0;i<p;i++)
    {
        for (j=0;j<r;j++)
        {
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    return 0;
}