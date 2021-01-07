#include<bits/stdc++.h>
using namespace std;

void dfs1(vector<int> adj[],int u,vector<int>&visited,stack<int>&s)
{
  visited[u]=1;
  for(int i=0;i<adj[u].size();i++)
  {
    if(visited[adj[u][i]]==0)
      dfs1(adj,adj[u][i],visited,s);
  }
  s.push(u);
  return;
}
void dfs2(vector<int> adj[],int u,vector<int>&visited)
{
  visited[u]=0;
  for(int i=0;i<adj[u].size();i++)
  {
    if(visited[adj[u][i]]==1)
      dfs2(adj,adj[u][i],visited);
  }
  cout<<u<<" ";
  return;
}
int kosaraju(int V, vector<int> adj[])
{
  vector<int>visited(V,0);
  stack<int>s;
  for(int i=0;i<V;i++)
  {
    if(visited[i]==0)
      dfs1(adj,i,visited,s);
  }
  vector<int>newadj[V];
  for(int i=0;i<V;i++)
  {
    for(int j=0;j<adj[i].size();j++)
      newadj[adj[i][j]].push_back(i);
  }
  int c=0;
  while(!s.empty())
  {
    while(!s.empty()&&visited[s.top()]==0)
      s.pop();
    if(s.empty())
      return c;
    c++;
    dfs2(newadj,s.top(),visited);
    cout<<endl;
    s.pop();
  }
  return c;
}
int main() {
  cout<<"Enter number of nodes: ";
  int v;
  cin>>v;
  cout<<"Enter number of edges: ";
  int e;
  cin>>e;
  vector<int> adj[v];
  cout<<"\nNOTE 1: For undirected edge enter two different edges\n";
  cout<<"\nNOTE 2: Nodes are numbered from 0 to v-1\n\n";
  for(int i=0;i<e;i++)
  {
    cout<<"\nEnter details of edge "<<i+1<<endl;
    int start,end;
    cout<<"Enter start node: ";
    cin>>start;
    cout<<"Enter end node: ";
    cin>>end;
    adj[start].push_back(end);
  }
  cout<<"\nStrongly connected componets are: "<<endl;
  int n=kosaraju(v,adj);
  cout<<"\nNumber of Strongly Connected Components is "<<n;
  return 0;
}
