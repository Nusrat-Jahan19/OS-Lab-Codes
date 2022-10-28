#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
    int p,n,frame;

    printf("Number of pages: ");
    scanf("%d",&p);

    printf("Number of page References: ");
    scanf("%d",&n);

    printf("Reference String: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);

    }
    printf("Number of Memory Page Frame: ");
    scanf("%d",&frame);


    int memory [frame];
    for (int i = 0; i < frame; i++)
    {
        memory[i] = -1;
    }
    int hit = 0;
    int fault = 0;
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < frame; j++)
        {
            if (memory[j] == a[i])
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            hit++;
        }
        else
        {
            fault++;
            bool check = false;
            for (int j = 0; j < frame; j++)
            {
                if (memory[j] == -1)
                {
                    memory[j] = a[i];
                    check = true;
                    break;
                }
            }
            if (!check)
            {
                int index = -1;
                int mx = -1;
                for (int j = 0; j < frame; j++)
                {
                    int dis = n;
                    for (int k = i + 1; k < n; k++)
                    {
                        if (memory[j] == a[k])
                        {
                            dis = k;
                            break;
                        }
                    }
                    if (dis - i > mx)
                    {
                        mx = dis - i;
                        index = j;
                    }
                }
                memory[index] = a[i];
            }
            for(int k=0; k<frame; k++)
            {
                printf("%d ",memory[k]);
            }
            printf("\n");
        }
    }
    cout << "Number of page fault: " << fault << "\n";


    return 0;
}


/*
8
22
7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1
3
*/
