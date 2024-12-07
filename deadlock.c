#include<stdio.h>

int main()
{
    int p,r;
    printf("Enter the no of process: ");
    scanf("%d",&p);
    printf("Enter the no of resources: ");
    scanf("%d",&r);
    int alloc[p][r];
    int req[p][r];
    int avail[r];
    printf("Enter the allocation matrix: ");
    int i,j;
    for(i=0;i<p;i++)
        for(j=0;j<r;j++)
            scanf("%d",&alloc[i][j]);
    printf("Enter the request matrix: ");
    for(i=0;i<p;i++)
        for(j=0;j<r;j++)
            scanf("%d",&req[i][j]);
    printf("Enter the available resources: ");
    for(i=0;i<r;i++)
        scanf("%d",&avail[i]);

    int flag[p];
    for ( i = 0; i < p; i++)
    {
        flag[i]=0;
    }
    
    for (int k = 0; k < p; k++)
    {
        for ( i = 0; i < p; i++)
        {
            if (flag[i]==0)
            {
                int fl=0;
                for ( j = 0; j < r; j++)
                {
                    if (req[i][j]>avail[j])
                    {
                        fl=1;
                        break;
                    }
                }
                if (fl==0)
                {
                    flag[i]=1;
                    for (int m = 0; m < r; m++)
                    {
                        avail[m]+=alloc[i][m];
                    }
                }
            }
        }
    }
    int fl=0;
    for ( i = 0; i < p; i++)
    {
        if (flag[i]==0)
        {
            fl=1;
            break;
        }
    }
    if (fl==1)
        printf("Deadlock.\n");
    else
        printf("No Deadlock.\n");
}