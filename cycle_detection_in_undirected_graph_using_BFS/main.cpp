#include <bits/stdc++.h>

using namespace std;

class graph
{
public:
    unordered_map<int, set<int>>adj;

    void add_edge(int u, int v, int direction)
    {
        adj[u].insert(v);
        if(direction==0)
        {
            adj[v].insert(u);
        }
    }

    void breadth_first_search(unordered_map<int, bool>&visited, vector<int>&bfs, int node)
    {
        queue<int>q;
        q.push(node);
        visited[node]=true;

        while(!q.empty())
        {
            int frontnode= q.front();
            q.pop();

            bfs.push_back(frontnode);

            for(auto it:adj[frontnode])
            {
                if(!visited[it])
                {
                    q.push(it);
                    visited[it]=true;
                }
            }
        }
    }

    void print_bfs(vector<int>bfs)
    {
        for(auto it:bfs)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }

    bool is_cycle_det_undir(unordered_map<int, bool>&visited, int node)
    {
        queue<int>q;
        unordered_map<int, int> parent;
        q.push(node);
        visited[node]=true;
        parent[node]=-1;

        while(!q.empty())
        {
            int frontnode= q.front();
            q.pop();

            for(auto neighbor:adj[frontnode])
            {
                if(visited[neighbor]==true && neighbor!=parent[frontnode])
                {
                    return true;
                }
                else if(!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor]=true;
                    parent[neighbor]= frontnode;
                }
            }
        }

        return false;
    }

    void print_graph()
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
    int n,m;
    cout<<"enter the number of nodes-"<<endl;
    cin>>n;

    cout<<"enter the number of edges-"<<endl;
    cin>>m;

    cout<<"enter the edges-"<<endl;
    int u,v;
    graph g;
    for(int i=0;i<m;i++)
    {
       cin>>u>>v;
       g.add_edge(u,v,0);
    }

    cout<<"the adjacency list representation of the above graph is-"<<endl;
    g.print_graph();

    //breadth first search

    unordered_map<int, bool> visited;
    vector<int>bfs;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            g.breadth_first_search(visited, bfs, i);
        }
    }
    cout<<"the breadth first search of the above graph is-"<<endl;
    g.print_bfs(bfs);

    // cycle detection in undirected graph using BFS

    bool is_cycle;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            is_cycle= g.is_cycle_det_undir(visited, i);
        }
    }
    if(is_cycle)
    {
        cout<<"cycle detected in the entered graph";
    }
    else
    {
        cout<<"cycle not detected in the entered graph";
    }
}
