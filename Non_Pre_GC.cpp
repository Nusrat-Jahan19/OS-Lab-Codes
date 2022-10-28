#include<iostream>
#include<iomanip>
using namespace std;
class priority_alg
{
    int pr[10],id[10],exe[10];
    int n;
    void sort(int *f,int *mid,int *last);
public:
    void getdata();
    void display();
    void cal_wt_tt();
};
void priority_alg::getdata()
{
    cout<<"How many process to be entered : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter execution time and priority of "<<i+1<<" process : ";
        cin>>exe[i]>>pr[i];
        id[i]=i+1;
    }
}
void priority_alg::display()
{
    cout<<endl<<"Process ID\tExecution time\tPriority "<<endl;
    for(int i=0;i<n;i++)
        cout<<setw(5)<<id[i]<<setw(15)<<exe[i]<<setw(15)<<pr[i]<<endl;
}
void priority_alg::sort(int *f,int *mid,int *last)
{
    int temp;
    for(int y=0;y<n-1;y++)
    {
        for(int z=0;z<n-1;z++)
            if(f[z]>f[z+1])
            {
                temp=f[z];
                f[z]=f[z+1];
                f[z+1]=temp;
                temp=mid[z];
                mid[z]=mid[z+1];
                mid[z+1]=temp;
                temp=last[z];
                last[z]=last[z+1];
                last[z+1]=temp;
            }
    }
}
void priority_alg::cal_wt_tt()
{
 float avg=0,avtnt=0,wt=0,tnt=0;
    sort(pr,id,exe);
    cout<<"\nProcess id \tWaiting time \tTurn around time "<<endl;
    for(int i=0;i<n;i++)
    {
        tnt+=exe[i];
        avtnt+=tnt;
        avg+=wt;
        cout<<setw(5)<<id[i]<<setw(15)<<tnt<<setw(15)<<wt<<endl;
        wt+=exe[i];
    }
    avg=avg/(float)n;
    avtnt/=(float)n;
    cout<<"\nAverage Waiting time     : "<<avg;
    cout<<"\nAverage turn Around time : "<<avtnt<<endl;
}
int main()
{
 priority_alg priority;
 priority.getdata();
 priority.display();
 priority.cal_wt_tt();
    return 0;
}
