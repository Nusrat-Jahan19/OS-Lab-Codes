#include<bits/stdc++.h>
using namespace std;

int main()
{

    int numberOfBlock;
    int numberOfRequest;

    cout<<"Enter number of block: ";
    cin>>numberOfBlock;
    cout<<endl;

    cout<<"Enter number of request: ";
    cin>>numberOfRequest;
    cout<<endl;

    vector<int> block(numberOfBlock);
    vector<int> request(numberOfRequest);


    cout << "Memory Block : ";

    for (int i=0; i<numberOfBlock; i++ )
    {
        cin>>block[i];
    }

    cout << endl;

    cout << "Memory Request : ";

    for (int i=0; i<numberOfRequest; i++ )
    {
        cin>>request[i];
    }

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
        for(int j=1; j<=numberOfBlock; j++)
        {
            if(!found && block[j-1]>=request[i])
            {
                finish[i] = 1;
                block[j-1] -= request[i];
                found = true;
                request_completed++;
            }

            output[j][i] = block[j-1];
            external_frag += block[j-1];
        }

        if(!found)
            break;
    }


    cout << endl;

    for(int i=0; i<=numberOfBlock; i++)
    {
        if(i>0)
            cout << "Block " << i ;
        else
            cout << "Request" ;

        for(int j=0; j<numberOfRequest; j++)
        {
            if(i==0)
                cout << "\t " << output[i][j] << " ";

            else
            {
                if(finish[j])
                    cout <<"\t " << output[i][j] <<  " ";
                else
                {
                    cout << "\t " << "---" << " ";
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
