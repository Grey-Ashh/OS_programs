#include<stdio.h>

int main()
{
    int n;
    printf("Enter the no of processes: ");
    scanf("%d",&n);
    int p[n],at[n],bt[n],pri[n],ct[n],tat[n],wt[n];
    int i,j,temp1,temp2,temp3,temp4;
    printf("Enter the AT in order: ");
    for (i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
        p[i]=i;
    }
    printf("Enter the BT in order: ");
    for (i=0;i<n;i++)
        scanf("%d",&bt[i]);

    printf("Enter the Priority in order: ");
    for (i=0;i<n;i++)
        scanf("%d",&pri[i]);
    
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(at[j]>at[j+1])
            {
                temp1=p[j];
                p[j]=p[j+1];
                p[j+1]=temp1;

                temp2=at[j];
                at[j]=at[j+1];
                at[j+1]=temp2;

                temp3=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp3;

                temp4=pri[j];
                pri[j]=pri[j+1];
                pri[j+1]=temp4;
            }
        }
    }

    for(i=1;i<n;i++)
    {
        for(j=1;j<n-i;j++)
        {
            if(pri[j]>pri[j+1])
            {
                int temp1=p[j];
                p[j]=p[j+1];
                p[j+1]=temp1;

                temp2=at[j];
                at[j]=at[j+1];
                at[j+1]=temp2;

                temp3=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp3;

                temp4=pri[j];
                pri[j]=pri[j+1];
                pri[j+1]=temp4;
            }
        }
    }

    for(i=1;i<n;i++)
    {
        for(j=1;j<n-i;j++)
        {
            if(pri[j]==pri[j+1])
            {
                if(at[j]>at[j+1])
                {
                    int temp1=p[j];
                    p[j]=p[j+1];
                    p[j+1]=temp1;

                    temp2=at[j];
                    at[j]=at[j+1];
                    at[j+1]=temp2;

                    temp3=bt[j];
                    bt[j]=bt[j+1];
                    bt[j+1]=temp3;
                    
                    temp4=pri[j];
                    pri[j]=pri[j+1];
                    pri[j+1]=temp4;
                }   
            }
        }
    }

    ct[0]=at[0]+bt[0];
    for(i=1;i<n;i++)
    {
        int temp=0;
        if(at[i]>ct[i-1])
        {
            temp=at[i]-ct[i-1];
        }
        ct[i]=ct[i-1]+bt[i]+temp;
    }

    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }

    printf("the table is: \n");
    printf("No\tAT\tBT\tPRI\tCT\tTAT\tWT\n");
    for (i=0;i<n;i++)
    {
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],pri[i],ct[i],tat[i],wt[i]);
    }
}