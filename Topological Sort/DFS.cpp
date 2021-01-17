#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>adj,stack<int>&s,vector<int>&visited,int u)
{
  visited[u]=1;
  for(int i=0;i<adj[u].size();i++)
  {
    if(visited[adj[u][i]]==0)
      dfs(adj,s,visited,adj[u][i]);
  }
  s.push(u);
}

int main() {
  int n;
  cout<<"Enter total number of nodes: ";
  cin>>n; 
  cout<<"Enter number of edges: ";
  int e;
  cin>>e;
  vector<vector<int>>edges;
  cout<<"\nNOTE : Topological sort is possible only for directed acyclic graph (DAG)\n\n";
  cout<<"NOTE : Nodes are numbered from 0 to n-1\n\n";
  for(int i=0;i<e;i++)
  {
    cout<<"Enter details of edge "<<i+1<<endl;
    int start,end;
    cout<<"FROM:   ";
    cin>>start;
    cout<<"TO:     ";
    cin>>end;
    edges.push_back({start,end});
  }
  vector<vector<int>>adj(n);  
  for(int i=0;i<edges.size();i++)
    adj[edges[i][0]].push_back(edges[i][1]);
  
  vector<int>visited(n,0);
  stack<int>st;
  for(int i=0;i<n;i++)
    if(visited[i]==0)
      dfs(adj,st,visited,i);
  vector<int>s;
  while(!st.empty())
  {
    s.push_back(st.top());
    st.pop();
  }  
  cout<<"\nTopological Sort is: ";
  for(auto i:s)
    cout<<i<<" ";
  return 0;  
}
