#include <bits/stdc++.h>

using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;

    void add_edge(int u, int v, bool direction)
    {
       //direction=0 -> undirected
       //direction=1 -> directed

       //create an edge between u to v

       adj[u].push_back(v);
       if(direction==0)
       {
           adj[v].push_back(u);
       }
    }

    void print_adjacency_list()
    {
       for(auto it:adj)
       {
           cout<<it.first<<"-> ";
           for(auto j:it.second)
           {
               cout<<j<<",";
           }
           cout<<endl;
       }
    }
};

int main()
{
    int n;
    cout<<"enter the number of vertices or nodes"<<endl;
    cin>>n;
    int m;
    cout<<"enter the number of edges"<<endl;
    cin>>m;
    //creating the graph
    graph g;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g.add_edge(u,v,0);
    }

    //printing the graph
    g.print_adjacency_list();
}
