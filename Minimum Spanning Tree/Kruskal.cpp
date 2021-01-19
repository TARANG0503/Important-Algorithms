#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int>vec1,vector<int>vec2)
{
  return vec1[2]<vec2[2];
}
int find(int x,vector<int>&parent)
{
  if(parent[x]==-1)
    return x;
  else
    return parent[x]=find(parent[x],parent);
}
void union_find(int x,int y,vector<int>&rank,vector<int>&parent)
{
  if(rank[x]==rank[y])
  {
    parent[x]=y;
    rank[y]++;
  }
  else if(rank[x]<rank[y])
    parent[x]=y;
  else
    parent[y]=x;
}
int kruskal(int n,vector<vector<int>>edges) {
    vector<int>parent(n+1,-1);
    vector<int>rank(n+1,0);
    sort(edges.begin(),edges.end(),comparator);
    int c=0;
    int sum=0;
    int i=0;
    while(c<n-1&&i<n)
    {
      int x=find(edges[i][0],parent);
      int y=find(edges[i][1],parent);
      if(x==y)
      {
        i++;
        continue;
      }      
      union_find(x,y,rank,parent);   
      c++;
      sum+=edges[i][2];
      // cout<<edges[i][2]<<endl;
      i++;
    }
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
  cout<<"\n\nMinimum weight is: ";
  cout<<kruskal(v,edges);
  return 0;  
}
