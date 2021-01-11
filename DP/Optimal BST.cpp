#include <bits/stdc++.h>
using namespace std;

void computeCostTabe(vector<vector<float>>&cost,vector<vector<float>>&kTable,vector<float>frequency,int n)
{
  for(int diff=0; diff<=n; diff++)
  {
    for(int i=0;i<=n-diff;i++)
    {
      int j=i+diff;
      float low=INT_MAX;
      cost[i][j]=0;
      for(int k=i+1;k<=j;k++)
      {
        float temp=cost[i][k-1]+cost[k][j];
        if(temp<low)
        {
          low=temp;
          cost[i][j]=temp;
          kTable[i][j]=k;
        }
      }
      for(int f=i+1;f<=j;f++)
        cost[i][j]+=frequency[f];
    }
  }
  return;
}

void print(vector<vector<float>>vec,int start,int end)
{
  for(int i=start;i<=end;i++)
  {
    for(int j=start;j<=end;j++)
      cout<<vec[i][j]<<"  ";
    cout<<endl;
  }
}

int main() {
  int n;
  cout<<"Enter number of keys: \n";
  cin>>n;
  vector<float>frequency(n+1,0);
  cout<<"Enter frequency of keys:\n";
  for(int i=1;i<=n;i++)
    cin>>frequency[i];
  vector<vector<float>>cost(n+1,vector<float>(n+1,-1));
  vector<vector<float>>kTable(n+1,vector<float>(n+1,-1));
  computeCostTabe(cost,kTable,frequency,n);
  cout<<"\nOptimal cost to construct BST is: "<<cost[0][n]<<endl<<endl;
  cout<<"Cost Table: \n";
  print(cost,0,n);
  cout<<endl;
  cout<<"K Table: \n";
  print(kTable,0,n);
  return 0;    
}
