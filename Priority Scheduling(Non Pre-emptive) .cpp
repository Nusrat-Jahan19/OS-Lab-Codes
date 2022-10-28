#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pid;
    int bt;
    int art;
    int prt;
};


int main()
{

    cout << "Enter the number of process : ";
    int n;
    cin>>n;
    Process proc[n+1];

    cout << "Enter the CPU times :\n";
    for(int i=0; i<n; i++)
    {
        cin>>proc[i].bt;
        proc[i].pid=i+1;
    }
    cout << "Enter the arrival times :\n";
    for(int i=0; i<n; i++)
    {
        cin>>proc[i].art;
    }


    cout << "Enter the priority :\n";
    for(int i=0; i<n; i++)
    {
        cin>>proc[i].prt;

    }
    int wt[n],rt[n],tat[n], total_wt = 0,total_tat = 0;

    for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;

    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;


    while (complete != n)
    {

        for (int j = 0; j < n; j++)
        {
            if ((proc[j].art<= t) && (proc[j].prt < minm) && rt[j] > 0)
            {
                minm = proc[j].prt;
                shortest = j;

            }
        }

        rt[shortest]--;

        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;

        if (rt[shortest] == 0)
        {

            complete++;

            finish_time = t + 1;

            wt[shortest] = finish_time - proc[shortest].bt - proc[shortest].art;

            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }

        t++;
    }

    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];

    printf("\nSample Output:\n");

    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("\nProcess%d:Waiting Time:%d \tTurnaround Time:%d\n",proc[i].pid,wt[i],tat[i]);
    }

    printf("\n\nAverage Waiting Time: %f", (float)total_wt / (float)n);
    printf("\n\nAverage Turnaround Time: %f\n", (float)total_tat / (float)n);
    return 0;
}
