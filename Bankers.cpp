#include<stdio.h>
#include<conio.h>
int main()
{
    int pro,i,j, res, k=0, d=0, t=0, count=0;
    int allocated[100][100], MAX[100][100], need[100][100], available[100], output[100], P[100], ins[100];

    printf("\n Enter the no. of processes : ");
    scanf("%d", &pro);
    printf("\n");

    printf("\n Enter the no. of resources : ");
    scanf("%d", &res);

    for (i=0; i<res; i++)
    {
        available[i]=0;

    }


    for (i=0; i<res; i++)
    {

        for (i=0; i <pro; i++)
        {
            P[i]=i;
            printf("Process %d  ",P[i]);
            printf("\n");

            for(j=0; j<res; j++)
            {

                printf("Maximum value for resource %d :",(j+1));
                scanf("%d", &MAX[i][j]);

            }

            for (j=0; j<res; j++)
            {
                printf("Allocated from resource %d :",(j+1));
                scanf("%d",&allocated[i][j]);
                available[j]+=allocated[i][j];
            }

            printf("\n");

        }
    }

    for (i=0; i<res; i++)
    {

        printf("Enter the total value of resource %d = ",(i+1));
        scanf("%d",&ins[i]);
    }


    for (i=0; i<res; i++)
    {
        available[i]=ins[i]-available[i];
    }
    printf("\n");

A:
    d=-1;
    for (i=0; i <pro; i++)
    {
        count=0;
        t=P[i];
        for (j=0; j<res; j++)
        {
            need[t][j] = MAX[t][j]-allocated[t][j];
            if(need[t][j]<=available[j])
                count++;
        }
        if(count==res)
        {
            output[k++]=P[i];
            for (j=0; j<res; j++)
                available[j]+=allocated[t][j];
        }
        else
            P[++d]=P[i];
    }
    if(d!=-1)
    {
        pro=d+1;
        goto A;
    }

    printf("The system is currently in safe state and < ");
    for (i=0; i<k; i++)
        printf(" P[%d] ",output[i]);
    printf(">is the safe sequence\n");
    getch();
}


/*
4
3
3
2
2
1
0
0
6
1
3
5
1
1
3
1
4
2
1
1
4
2
2
0
0
2
9
3
6
*/
