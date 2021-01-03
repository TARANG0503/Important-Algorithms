#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>adj)
{
  for(int i=1;i<adj.size();i++)
  {
    for(int j=1;j<adj[0].size();j++)
    {
      if(adj[i][j]>100)
        cout<<"∞ ";
      else
        cout<<adj[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl<<endl;
}

int main() {
  cout<<"Enter number of nodes: ";
  int v;
  cin>>v;
  cout<<"Enter number of edges: ";
  int e;
  cin>>e;
  vector<vector<int>>edges;
  cout<<"\nNOTE: Nodes are numbered from 1 to v\n\n";
  for(int i=0;i<e;i++)
  {
    cout<<"Enter details of edge "<<i+1<<endl;
    int start,end,wt;
    cout<<"Enter start node: ";
    cin>>start;
    cout<<"Enter end node: ";
    cin>>end;
    cout<<"Enter edge weight: ";
    cin>>wt;
    edges.push_back({start,end,wt});
  }
  vector<vector<int>>adj(v+1,vector<int>(v+1,1000));
  for(int i=1;i<=v;i++)
    adj[i][i]=0;
  for(int i=0;i<edges.size();i++)
    adj[edges[i][0]][edges[i][1]]=edges[i][2];
  cout<<"\n\nK=0:\n";
  print(adj);
  for(int k=1;k<=v;k++)
  {
    for(int i=1;i<=v;i++)
    {
      for(int j=1;j<=v;j++)
      {
        adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
      }
    }
    cout<<"K="<<k<<endl;
    print(adj);    
  }
  return 0;  
}
