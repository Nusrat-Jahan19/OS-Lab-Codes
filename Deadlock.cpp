#include <bits/stdc++.h>
using namespace std;

#define GREY 1
#define WHITE 0
#define BLACK 2

int color1[100000];
vector <int> adj[100000];
int counter;
map<char, int> m1;
map<int, char> m2;
int n,e;

void dfs1(int u,vector<int>greyList)
{
    color1[u] = GREY;
    greyList.push_back(u);

    int s = adj[u].size();

    for(int i = 0; i < s; i++)
    {
        int v = adj[u][i];

        vector<int>::iterator it;
        it = find (greyList.begin(), greyList.end(), v);

        if(color1[v] == WHITE)
        {
            dfs1(v,greyList);
        }

        else if(color1[v]==GREY)
        {
            counter++;
            cout << "Deadlock Detected Among nodes: " << endl;

            vector<int>::iterator it1;

            for(it1=it ; it1!=greyList.end(); it1++)
            {
                cout << m2[*it1] << " ";
            }
            cout << endl;
            adj[u].erase(find(adj[u].begin(),adj[u].end(),v));
        }
    }

    color1[u] = BLACK;
}
void dfs2()
{

    vector<int>greyList;

    for(int i =0; i<n; i++)
    {
        if(color1[i]==0)
        {
            greyList.clear();
            dfs1(i,greyList);
        }
    }

    for(int i =0; i<n; i++)
    {
        color1[i]= 0;
    }

    counter = 0;

    for(int i =0; i<n; i++)
    {
        if(color1[i]==0)
        {
            greyList.clear();
            dfs1(i,greyList);
        }
    }

    if(counter==1)
        cout << "No deadlock found " << endl;
}
int main()
{

    char c;
    cout << "Enter the number of nodes : ";
    cin >> n;
    cout << "Node Names : ";
    for(int i =0; i<n; i++)
    {
        cin >> c;
        m1[c] = i;
        m2[i] = c;
    }

    getchar();

    map <char, int> :: iterator it;

    cout << "Enter the number of edges : " << endl;
    cin >> e;
    getchar();
    cout << "Edges : " << endl;
    char s1,s2;
    while( e--)
    {
        cin>>s1>>s2;
        adj[m1[s1]].push_back(m1[s2]);
    }
    dfs2();
    return 0;
}

/*
13
R A S C F W D B T E V G U
13
R A
A S
C S
W F
F S
D S
D T
B T
T E
E V
V G
G U
U D
*/

