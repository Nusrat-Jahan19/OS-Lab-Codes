#include<bits/stdc++.h>
using namespace std;

void DiskFCFS()
{

    int headNum;
    vector<int> q;

    int current;
    int requestNum;

    cout << "Number of heads : ";
    cin >> headNum;

    cout << "Number of request : ";
    cin >> requestNum;

    cout << "Cylinder Requests : ";

    for(int i=0; i<requestNum; i++)
    {
        int x;
        cin >> x;
        q.push_back(x);
    }

    cout << "Current Head Position : ";
    cin >> current;

    int fcfs_cylinder_move = 0;

    cout << current ;

    for(int i=0; i<requestNum; i++)
    {
        cout << "->" <<q[i];
        fcfs_cylinder_move += abs(current-q[i]);
        current = q[i];
    }
    cout << endl;

    cout << "Cylinder Movement " <<fcfs_cylinder_move << endl;

}


void DiskSSTF()
{

    int headNum;
    vector<int> q;
    vector<int> :: iterator it;

    int current;
    int requestNum;
    int sstf_cylinder_move = 0;
    int request_complete = 0;

    cout << "Number of heads : ";
    cin >> headNum;

    cout << "Number of request : ";
    cin >> requestNum;

    cout << "Cylinder Requests : ";

    for(int i=0; i<requestNum; i++)
    {
        int x;
        cin >> x;
        q.push_back(x);
    }

    sort(q.begin(),q.end());

    for(int x :q)
        cout << x  << " ";

    cout << endl;

    cout << "Current Head Position : ";
    cin >> current;

    cout << current;

    while(q.size()!=0)
    {
        int nextClosestDistance = headNum+1;
        int nextClosestIndex = -1;

        for(it=q.begin(); it!=q.end(); it++)
        {
            if(abs(current-*it)<nextClosestDistance)
            {
                nextClosestDistance = abs(current-*it);
                nextClosestIndex = it-q.begin();
            }
        }

        sstf_cylinder_move += nextClosestDistance;
        current = q[nextClosestIndex];
        cout << "->" << current ;

        q.erase(q.begin()+nextClosestIndex);
    }

    cout << endl;

    cout << "Cylinder Movement " <<sstf_cylinder_move << endl;

}


void DiskCSCAN()
{

    int headNum;
    int current;
    int requestNum;
    int cscan_cylinder_move = 0;
    int request_complete = 0;

    cout << "Number of heads : ";
    cin >> headNum;

    vector<int> q(headNum+2, 0);

    cout << "Number of request : ";
    cin >> requestNum;

    cout << "Cylinder Requests : ";

    for(int i=0; i<requestNum; i++)
    {
        int x;
        cin >> x;
        q[x] = 1;
    }

    cout << "Current Head Position : ";
    cin >> current;

    cout << current;

    int fast = current;

    while(request_complete!=requestNum)
    {
        fast++;

        if(fast>=headNum)
        {
            fast = 0;
            current = 0;
        }

        if(q[fast]==1)
        {
            cout << "->" << fast;
            cscan_cylinder_move += abs(fast-current);
            current = fast;
            request_complete++;
        }
    }
    cout << endl;

    cout << "Cylinder Movement : " << cscan_cylinder_move << endl;

}


int main()
{

    int ch;
    char c,option;

    do
    {
        printf("\nEnter your choice for Disk-Arm scheduling: \n 1.FCFS \n 2.SSTF \n 3.CSCAN \n \n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            DiskFCFS();
            break;
        case 2:
            DiskSSTF();
            break;
        case 3:
            DiskCSCAN();
            break;
        }
        printf("\nDO U WANT TO CONTINUE(Y/N) ?: ");
        scanf("%c",&option);
        scanf("%c",&c);
    }
    while((c=='y')||(c=='Y'));

}


/*
200
8
98 183 37 122 14 124 65 67
53
*/

