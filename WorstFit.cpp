#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    vector<int> block;
    vector<int> request;

    int x;

    cout << "Memory Block : ";
    while(cin >> x)
    {
        block.push_back(x);
    }

    cin.clear();
    cout << endl;

    cout << "Memory Request : ";
    while(cin>> x)
    {
        request.push_back(x);
    }

    int numberOfBlock = block.size();
    int numberOfRequest  = request.size();
    int finish[numberOfRequest] = {0};
    int external_frag = 0;
    int request_completed = 0;

    int output[numberOfBlock+1][numberOfRequest] = {0};

    for(int i=0; i<numberOfRequest; i++)
    {
        output[0][i] = request[i];
    }

    for(int i=0; i<numberOfRequest; i++)
    {
        bool found = false;
        external_frag = 0;

        int largest_allocation = -1;
        int largest_index = -1;

        for(int j=1; j<=numberOfBlock; j++)
        {
            if(block[j-1]>=request[i])
            {
                found = true;
                finish[i] = 1;
                if(largest_allocation<block[j-1])
                {
                    largest_allocation = block[j-1];
                    largest_index = j;
                }
            }
            output[j][i] = block[j-1];
            external_frag += block[j-1];
        }


        if(!found)
            break;
        else
        {
            block[largest_index-1] -= request[i];
            output[largest_index][i] = block[largest_index-1];
            external_frag -= request[i];
            request_completed++;
        }

    }

    cout << endl;

    for(int i=0; i<=numberOfBlock; i++)
    {
        if(i>0)
            cout << "Block " << i << setw(5);
        else
            cout << "Request" <<setw(5);

        for(int j=0; j<numberOfRequest; j++)
        {
            if(i==0)
                cout << setw(10) << output[i][j] << " ";

            else
            {
                if(finish[j])
                    cout << setw(10) << output[i][j] <<  " ";
                else
                {
                    cout << setw(10) << "---" << " ";
                }
            }

        }
        cout << endl;
    }

    if(request_completed == numberOfRequest)
    {
        cout << "No External Fragmentation" << endl;
    }
    else
    {
        cout << "External Fragmentation : " << external_frag << endl;
    }

    return 0;
}


/*
50 200 70 115 15
100 10 35 15 23 6 25 55 88 40
*/
