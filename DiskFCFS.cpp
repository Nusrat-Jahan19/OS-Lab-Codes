#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int headNum;
    vector<int> q;

    int current;
    int requestNum;

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

    cout << "Current Head Position : ";
    cin >> current;

    int fcfs_cylinder_move = 0;

    cout << current ;

    for(int i=0;i<requestNum;i++)
    {
        cout << "->" <<q[i];
        fcfs_cylinder_move += abs(current-q[i]);
        current = q[i];
    }
    cout << endl;

    cout << "Cylinder Movement " <<fcfs_cylinder_move << endl;

    return 0;
}

/*
200
8
98 183 37 122 14 124 65 67
53
*/
