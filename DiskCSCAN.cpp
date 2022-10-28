
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

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

    for(int i=0;i<requestNum;i++)
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

    return 0;
}

/*
200
8
98 183 37 122 14 124 65 67
53
*/


