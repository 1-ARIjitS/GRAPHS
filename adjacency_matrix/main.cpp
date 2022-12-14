#include <bits/stdc++.h>

using namespace std;

int main()
{
    // n-> number of vertices
    // m-> number of edges
    int n,m;
    cout<<"Enter the number of vertices or nodes-"<<endl;
    cin>>n;
    cout<<"Enter the number of edges-"<<endl;
    cin>>m;
    //creation of adjacency matrix
    int adj[n][n]={0};

    int u,v;
    cout<<"Enter the edges-"<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        //filling up the adjacency matrix
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==u-1 && j==v-1)
                {
                    adj[i][j]=1;
                    adj[j][i]=1;
                }
            }
        }
    }

    //printing the graph
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}
