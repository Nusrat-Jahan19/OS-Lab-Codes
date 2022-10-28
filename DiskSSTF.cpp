#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

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

    for(int i=0;i<requestNum;i++)
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

        for(it=q.begin();it!=q.end();it++)
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

    return 0;
}

/*
200
8
98 183 37 122 14 124 65 67
53
*/


