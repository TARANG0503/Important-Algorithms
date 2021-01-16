#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cout<<"Enter total number of nodes: ";
  cin>>n; 
  cout<<"Enter number of edges: ";
  int e;
  cin>>e;
  vector<vector<int>>edges;
  cout<<"\nNOTE : Topological sort is possible only for directed acyclic graph (DAG)\n\n";
  cout<<"\nNOTE : Nodes are numbered from 0 to n-1\n\n";
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
  vector<int>indegree(n,0);
  for(int i=0;i<edges.size();i++)
  {
    adj[edges[i][0]].push_back(edges[i][1]);
    indegree[edges[i][1]]++;
  }
  
  queue<int>q;
  for(int i=0;i<n;i++)
    if(indegree[i]==0)
      q.push(i);
  
  int c=0;
  vector<int>s;
  while(!q.empty())
  {
    int u=q.front();
    s.push_back(u);
    q.pop();
    c++;
    for(int i=0;i<adj[u].size();i++)
    {
      int temp=adj[u][i];
      indegree[temp]--;
      if(indegree[temp]==0)
        q.push(temp);
    }
  }
  if(c!=n)
    cout<<"Topological sort not possible";
  for(auto i:s)
    cout<<i<<" ";
  return 0;  
}
