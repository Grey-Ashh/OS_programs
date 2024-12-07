#include<stdio.h>

int mutex=1;
int full=0;
int empty=10;
int x=0;

void signalmutex()
{
    mutex++;
}

void waitmutex()
{
    while(mutex<0);
    mutex--;
}

void signalempty()
{
    empty++;
}

void waitempty()
{
    empty--;
}

void signalfull()
{
    full++;
}

void waitfull()
{
    full--;
}

void producer()
{
    waitmutex();
    waitempty();
    x++;
    printf("Producer produced item %d\n",x);
    printf("full %d\n",full);
    printf("empty %d\n",empty);
    signalfull();
    signalmutex();
}
void consumer()
{
    waitmutex();
    waitfull();
    printf("consumer consumed item %d\n",x);
    printf("full %d\n",full);
    printf("empty %d\n",empty);
    x--;
    signalempty();
    signalmutex();
}

int main()
{
    int c;
    int flag=1;
    printf("1.producer\n2.consumer\n3.exit\n");
    while (flag!=0)
    {
        printf("Enter choice: ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            if (mutex==1 && full!=10)
            {
                producer();
            }
            else
                printf("Buffer is full");
            break;
        case 2:
            if (mutex==1 && full>0)
            {
                consumer();
            }
            else
                printf("Buffer is empty\n");
            break;
        case 3:
            flag=0;
            break;
        default:
            printf("Wrong input.");
            break;
        }
    }
}