#include<bits/stdc++.h>
using namespace std;
struct process
{
    int id;
    int at,bt,wt,tt,rt;
    int completed;

} p[10];
int n;
int q[10];
int front=-1,rear=-1;
void enqueue(int i)
{
    if(rear==10)
        printf("overflow");
    rear++;
    q[rear]=i;
    if(front==-1)
        front=0;

}
bool compId(process a, process b)
{
    return a.id < b.id;
}

int dequeue()
{
    if(front==-1)
        printf("underflow");
    int temp=q[front];
    if(front==rear)
        front=rear=-1;
    else
        front++;
    return temp;
}
int ReadyQueue(int i)
{
    int k;
    for(k=front; k<=rear; k++)
    {
        if(q[k]==i)
            return 1;
    }
    return 0;

}
void sortByArrival()
{
    struct process temp;
    int i,j;
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
        {
            if(p[i].at>p[j].at)
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
}

int main()
{

    int i,j,time=0,sum_bt=0,tq;
    float avgwt=0,avgtt=0;
    printf("Enter the number of process :");
    scanf("%d",&n);
    printf("Enter the CPU times :\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&p[i].bt);
    }

    printf("Enter the arrival times :\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&p[i].at);
        p[i].rt=p[i].bt;
        p[i].completed=0;
        sum_bt+=p[i].bt;
        p[i].id=i+1;
    }

    //printf("\nEnter the time quantum:");
    //scanf("%d",&tq);
    tq=3;

    sortByArrival();
    enqueue(0);
    for(time=p[0].at; time<sum_bt;)
    {
        i=dequeue();

        if(p[i].rt<=tq)
        {

            time+=p[i].rt;
            p[i].rt=0;
            p[i].completed=1;
            p[i].wt=time-p[i].at-p[i].bt;
            p[i].tt=time-p[i].at;

            for(j=0; j<n; j++)
            {
                if(p[j].at<=time && p[j].completed!=1&& ReadyQueue(j)!=1)
                {
                    enqueue(j);

                }
            }
        }
        else
        {
            time+=tq;
            p[i].rt-=tq;

            for(j=0; j<n; j++)
            {
                if(p[j].at<=time && p[j].completed!=1&&i!=j&& ReadyQueue(j)!=1)
                {
                    enqueue(j);

                }
            }
            enqueue(i);

        }

    }
    sort(p,p+n,compId);
    printf("\nSample Output:\n");
    for(i=0; i<n; i++)
    {
        avgwt+=p[i].wt;
        avgtt+=p[i].tt;
        cout << "Process " << p[i].id<< ": Waiting Time: " << p[i].wt << " Turnaround Time: " << p[i].tt<< endl;
    }


    printf("\nAverage Waiting Time: %f\n",avgwt/n);
    printf("\nAverage Turnaround Time: %f\n",avgtt/n);
}

