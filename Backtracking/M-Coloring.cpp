#include <bits/stdc++.h>
using namespace std;

bool isPossible(bool graph[101][101],int v,int u,int c,vector<int>&color)
{
    for(int i=0;i<v;i++)
    {
        if(graph[u][i]==1&&color[i]==c)
            return false;
    }
    return true;
}

bool helper(bool graph[101][101],int v,int u,int m,vector<int>&color)
{
    if(u>=v)
        return true;
    for(int curr=1;curr<=m;curr++)
    {
        if(isPossible(graph,v,u,curr,color))
        {
            color[u]=curr;
            if(helper(graph,v,u+1,m,color))
                return true;
            color[u]=0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int v) {
    vector<int>color(v,0);
    return helper(graph,v,0,m,color);
}

int main() {
    
    int n, m, e;
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter number of colors to be used: ";
    cin>>m;
    cout<<"Enter number of edges: ";
    cin>>e;
    cout<<"\nNOTE: Nodes are numbered from 0 to n-1 and graph is undirected"<<endl;
    bool graph[101][101];
    for (int i=0;i<n;i++) 
        memset(graph[i],0,sizeof(graph[i]));
    
    for (int i=0;i<e;i++) 
    {
        int a,b;
        cout<<"\nEnter two nodes of an edge "<<i+1<<endl;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    cout<<endl<<endl;
    if(graphColoring(graph, m, n))
        cout<<"Graph coloring POSSIBLE with m colors";
    else
        cout<<"Graph coloring NOT POSSIBLE with m colors";
    return 0;
}
