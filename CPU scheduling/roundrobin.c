#include<stdio.h>
int q[100];
int f=-1;
int r=-1;

void insert(int value)
{
    if(f==-1)
        f=0;
    r++;
    q[r]=value;
}

int delete()
{
    int value;
    value=q[f];
    f++;
    return value;
}

// void swap(int *a,int *b)
// {
//     int temp;
//     temp=*a;
//     *a=*b;
//     *b=temp;
// }

int main()
{
    int n,tq;
    int i,j,temp1,temp2,temp3;
    printf("Enter the no of procsess: ");
    scanf("%d",&n);
    int a[n][6];
    printf("Enter the time quantum: ");
    scanf("%d",&tq);
    printf("Enter the AT in order: ");
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i][1]);
        a[i][0]=i;
    }
    printf("Enter the BT in order: ");
    for (i=0;i<n;i++)
        scanf("%d",&a[i][2]);
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(a[j][1]>a[j+1][1]) 
            {
                //swap(&a[i][0],&a[i+1][0]);
                temp1=a[j][0];
                a[j][0]=a[j+1][0];
                a[j+1][0]=temp1;
                
                //swap(&a[i][1],&a[i+1][1]);
                temp2=a[j][1];
                a[j][1]=a[j+1][1];
                a[j+1][1]=temp2;
                
                //swap(&a[i][2],&a[i+1][2]);
                temp3=a[j][2];
                a[j][2]=a[j+1][2];
                a[j+1][2]=temp3;
            }
        }
    }

    int exist[n];
    int t=0;
    int bt[n];
    for (i=0;i<n;i++)
    {
        bt[i]=a[i][2];
        exist[i]=0;
    }
    insert(0);
    exist[0]=1;
    while (f<=r)
    {
        int p=delete();
        if(a[p][2]>=tq)
        {
            t=t+tq;
            a[p][2]=a[p][2]-tq;
        }
        else
        {
            t=t+a[p][2];
            a[p][2]=0;
        }

        for(i=1;i<n;i++)
        {
            if(exist[i]==0 && a[i][1]<=t)
            {
                insert(i);
                exist[i]=1;
            }
        }

        if(a[p][2]==0)
        {
            a[p][3]=t;
            // a[p][4]=t-a[i][1];
            // a[p][5]=a[i][4]-bt[p];
        }
        else
        {
            insert(p);
        }
    }
        for(i=0;i<n;i++)
    {
        a[i][4]=a[i][3]-a[i][1];
        a[i][5]=a[i][4]-bt[i];
    }
    printf("the table is: \n");
    printf("No\tAT\tBT\tCT\tTAT\tWT\n");
    for (i=0;i<n;i++)
    {
    printf("%d\t%d\t%d\t%d\t%d\t%d\n",a[i][0],a[i][1],bt[i],a[i][3],a[i][4],a[i][5]);
    }
}