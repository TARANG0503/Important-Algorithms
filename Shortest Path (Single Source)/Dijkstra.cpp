#include <bits/stdc++.h>
using namespace std;

#define INF 10000

int getShortestDistanceVertex(vector<int>shortestDist,vector<int>visited)
{
  int low=INF;
  int index=-1;
  for(int i=1;i<=shortestDist.size();i++)
  {
    if(visited[i]==0)
    {
      if(shortestDist[i]<low)
      {
        low=shortestDist[i];
        index=i;
      }
    }
  }
  return index;
}

int main() {
  cout<<"Enter number of nodes: ";
  int v;
  cin>>v;
  cout<<"Enter number of edges: ";
  int e;
  cin>>e;
  vector<vector<int>>edges;
  cout<<"\nNOTE : for UNDIRECTED edge enter two edges\n";
  cout<<"\nNOTE : Nodes are numbered from 1 to v\n\n";
  for(int i=0;i<e;i++)
  {
    cout<<"Enter details of edge "<<i+1<<endl;
    int start,end,wt;
    cout<<"FROM:   ";
    cin>>start;
    cout<<"TO:     ";
    cin>>end;
    cout<<"WEIGHT: ";
    cin>>wt;
    edges.push_back({start,end,wt});
  }
  vector<vector<int>>adj(v+1,vector<int>(v+1,0));
  
  for(int i=0;i<edges.size();i++)
  {
    adj[edges[i][0]][edges[i][1]]=edges[i][2];
  }

  cout<<"Enter the source vertex: "; 
  int sc;
  cin>>sc; 
  vector<int>shortestDist(v+1,INF);
  vector<int>visited(v+1,0);
  shortestDist[sc]=0;
  int u=getShortestDistanceVertex(shortestDist,visited);
  while(u!=-1)
  {
    visited[u]=1;
    //relaxation
    for(int i=1;i<=v;i++)
    {
      if(adj[u][i]>0&&adj[u][i]+shortestDist[u]<shortestDist[i])
        shortestDist[i]=adj[u][i]+shortestDist[u];
    }
    u=getShortestDistanceVertex(shortestDist,visited);
  }
  cout<<"Shortest distance of vertices from source vertex "<<sc <<" are:\n\n\n";
  cout<<" Vertex   Shortest distance\n";
  for(int i=1;i<=v;i++)
    cout<<"\t"<<i<<"\t\t\t"<<shortestDist[i]<<endl;
  return 0;  
}
