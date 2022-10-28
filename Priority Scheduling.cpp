#include<bits/stdc++.h>
using namespace std;
struct process
{

    int id;
    int cpuTime;
    int arrivalTime;
    int waitTime;
    int turnAroundTime;
    int priority;

};

bool compID(process a, process b)
{
    return a.id < b.id;
}

int main()
{
    int i,j,n,min,k=1,btime=0,tat=0,sum=0,temp;
    float wavg=0,tavg=0,totalTAT=0,totalWT=0;


    printf("Enter the number of process:");
    scanf("%d",&n);
    vector<process> v(n);


    printf("Enter the CPU times:\n");
    for(i=0; i<n; i++)
    {
        cin>>v[i].cpuTime;
        v[i].id=i+1;

    }

    printf("Enter the arrival times:\n");
    for(i=0; i<n; i++)
    {

        cin>>v[i].arrivalTime;
    }

    printf("Enter the priority:\n");
    for(i=0; i<n; i++)
    {

        cin>>v[i].priority;
    }

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if( v[i].arrivalTime<v[j].arrivalTime )
            {

                temp=v[j].arrivalTime;
                v[j].arrivalTime=v[i].arrivalTime;
                v[i].arrivalTime=temp;
                temp=v[j].cpuTime;
                v[j].cpuTime=v[i].cpuTime;
                v[i].cpuTime=temp;
                temp=v[j].id;
                v[j].id=v[i].id;
                v[i].id=temp;
                temp=v[j].priority;
                v[j].priority=v[i].priority;
                v[i].priority=temp;
            }
        }

    for(j=0; j<n; j++)
    {
        btime=btime+v[j].cpuTime;
        min=v[k].priority;
        for(i=k; i<n; i++)
        {
            if (btime>=v[i].arrivalTime && v[i].priority<min)
            {

                temp=v[k].arrivalTime;
                v[k].arrivalTime=v[i].arrivalTime;
                v[i].arrivalTime=temp;
                temp=v[k].cpuTime;
                v[k].cpuTime=v[i].cpuTime;
                v[i].cpuTime=temp;
                temp=v[k].id;
                v[k].id=v[i].id;
                v[i].id=temp;
                temp=v[j].priority;
                v[j].priority=v[i].priority;
                v[i].priority=temp;
            }
        }
        k++;
    }
    for(i=1; i<n; i++)
    {
        sum=sum+v[i-1].cpuTime;
        v[i].waitTime=sum-v[i].arrivalTime;
        totalWT=totalWT+v[i].waitTime;
    }

    wavg=(totalWT/n);
    for(i=0; i<n; i++)
    {
        v[i].turnAroundTime=v[i].waitTime+v[i].cpuTime;
        totalTAT=totalTAT+v[i].turnAroundTime;

    }

    tavg=(totalTAT/n);


    printf("\nSample Output:\n");
    sort(v.begin(),v.end(),compID);
    for(i=0; i<n; i++)
    {
        printf("\nProcess%d:Waiting Time:%d \tTurnaround Time:%d\n",v[i].id,v[i].waitTime,v[i].turnAroundTime);
    }


    printf("\n\nAverage Waiting Time: %f",wavg);
    printf("\n\nAverage Turnaround Time: %f\n",tavg);
    return 0;
}

