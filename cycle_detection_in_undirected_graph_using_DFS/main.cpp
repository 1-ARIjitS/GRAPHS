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

    void depth_first_search(unordered_map<int, bool>&visited, vector<int>&dfs, int node)
    {
        visited[node]=true;
        dfs.push_back(node);

        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                depth_first_search(visited, dfs, it);
            }
        }
    }

    void print_dfs(vector<int>dfs)
    {
        for(auto it:dfs)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }

    bool is_cycle_det_dfs(int parent, unordered_map<int, bool>&visited, int node)
    {
        visited[node]=true;

        for(auto neighbor:adj[node])
        {
            if(!visited[neighbor])
            {
                bool cycle_detected= is_cycle_det_dfs(node, visited, neighbor);
                if(cycle_detected)
                {
                    return true;
                }
            }
            else if(neighbor!=parent)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    int n,m;

    cout<<"enter the number of nodes-"<<endl;
    cin>>n;

    cout<<"enter the number of edges-"<<endl;
    cin>>m;

    graph g;
    int u,v;
    cout<<"enter the edges-"<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        g.add_edge(u,v,0);
    }

    cout<<"adjacency list representation of the above graph is-"<<endl;
    g.print_graph();

    //depth first search
    
    /*cout<<"the depth first search of the above graph is-"<<endl;
    unordered_map<int, bool>visited;
    vector<int>dfs;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            g.depth_first_search(visited, dfs, i);
        }
    }
    g.print_dfs(dfs);*/

    //cycle detection in undirected graph using depth first search
    bool is_cycle;
    unordered_map<int, bool>visited;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            is_cycle= g.is_cycle_det_dfs(-1, visited, i);
        }
    }
    if(is_cycle==true)
    {
        cout<<"cycle detected in the graph"<<endl;
    }
    else
    {
        cout<<"cycle not detected in the graph"<<endl;
    }
}
