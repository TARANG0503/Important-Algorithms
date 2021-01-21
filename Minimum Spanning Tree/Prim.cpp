#include <bits/stdc++.h>
using namespace std;

int getMin(vector<int>weight,vector<int>visited)
{
  int low=INT_MAX,index=0;
  for(int i=0;i<weight.size();i++)
  {
    if(weight[i]<low&&visited[i]==0)
    {
      low=weight[i];
      index=i;
    }
  }
  return index;
}
int prims(int n, vector<vector<int>> edges, int start) 
{
  start--;
  vector<vector<int>>adj(n,vector<int>(n,-1));
  vector<int>visited(n,0);
  vector<int>weight(n,INT_MAX);
  weight[start]=0;
  for(int i=0;i<edges.size();i++)
  {
    adj[edges[i][0]-1][edges[i][1]-1]=edges[i][2];
    adj[edges[i][1]-1][edges[i][0]-1]=edges[i][2];
  }
  for(int j=0;j<n-1;j++)
  {
    int x = getMin(weight,visited);
    visited[x]=1;
    for(int i=0;i<n;i++)
    {
      if(adj[x][i]>-1&&visited[i]==0)
        weight[i]=min(weight[i],adj[x][i]);
    }
  }
  int sum=0;
  for(int i=0;i<n;i++)
    sum+=weight[i];
  return sum;
}

int main() {
  cout<<"Enter number of nodes: ";
  int v;
  cin>>v;
  cout<<"Enter number of edges: ";
  int e;
  cin>>e;
  vector<vector<int>>edges;
  cout<<"\nNOTE : Nodes are numbered from 1 to v\n\n";
  for(int i=0;i<e;i++)
  {
    cout<<"\Details of edge "<<i+1<<endl;
    int start,end,wt;
    cout<<"Enter start node: ";
    cin>>start;
    cout<<"Enter end node: ";
    cin>>end;
    cout<<"Enter edge weight: ";
    cin>>wt;
    edges.push_back({start,end,wt});
  }
  cout<<"\nEnter Start vertex: ";
  int st;
  cin>>st;
  cout<<"\n\nMinimum weight is: ";
  cout<<prims(v,edges,st);
  return 0;  
}
