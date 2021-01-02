#include <bits/stdc++.h>
using namespace std;

#define INF 10000

int main() {
  cout<<"Enter number of nodes: ";
  int v;
  cin>>v;
  cout<<"Enter number of edges: ";
  int e;
  cin>>e;
  vector<vector<int>>edges;
  cout<<"\nNOTE 1: For undirected edge enter two different edges\n";
  cout<<"\nNOTE 2: Nodes are numbered from 1 to v\n\n";
  for(int i=0;i<e;i++)
  {
    cout<<"\nEnter details of edge "<<i+1<<endl;
    int start,end,wt;
    cout<<"Enter start node: ";
    cin>>start;
    cout<<"Enter end node: ";
    cin>>end;
    cout<<"Enter edge weight: ";
    cin>>wt;
    edges.push_back({start,end,wt});
  }
  vector<int>distance(v+1,INF);
  int sc,c=1,n=v-1;
  cout<<"\nEnter source vertex: ";
  cin>>sc;
  distance[sc]=0;
  while(n--&&c>0)
  {
    c=0;
    for(int i=0;i<edges.size();i++)
    {
      if(distance[edges[i][0]]+edges[i][2]<distance[edges[i][1]])
      {
        distance[edges[i][1]]=distance[edges[i][0]]+edges[i][2];
        c++;
      }
    }
  }
  //check for negative cycle
  c=0;
  for(int i=0;i<edges.size();i++)
  {
    if(distance[edges[i][0]]+edges[i][2]<distance[edges[i][1]])
    {
      distance[edges[i][1]]=distance[edges[i][0]]+edges[i][2];
      c++;
    }
  }
  if(c>0)
  {
    cout<<"\n\nGraph contains negative cycle... Shortest path can't be found";
    return 0;
  }
  cout<<"\n\nShortest distance of vertices from source vertex "<<sc <<
  " are:\n\n\n";
  cout<<" Vertex   Shortest distance\n";
  for(int i=1;i<=v;i++)
    cout<<"\t"<<i<<"\t\t\t"<<distance[i]<<endl;
  return 0;  
}
