#include <bits/stdc++.h>
using namespace std;

string getAns(vector<int>profit,vector<vector<int>>&dp,int m,int n)
{
  string ans="";
  int gain=dp[n][m];
  for(int i=n;i>0;i--)
  {
    if(find(dp[i-1].begin(),dp[i-1].end(),gain)==dp[i-1].end())
    {
      ans="1"+ans;
      gain-=profit[i];
    }
    else
      ans="0"+ans;
  }
  return ans;
}
void fillDpTable(vector<int>weight,vector<int>profit,vector<vector<int>>&dp,int m,int n)
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(j<weight[i])
        dp[i][j]=dp[i-1][j];
      else
        dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+profit[i]);
    }
  }
  return;
}

int main() {
  int m,n;
  cout<<"Enter max capacity of bag: ";
  cin>>m;
  cout<<"Enter no.of items: ";
  cin>>n;
  vector<int>weight(n+1,0);
  vector<int>profit(n+1,0);
  cout<<"Enter the weight of each item\n";
  for(int i=1;i<=n;i++)
    cin>>weight[i];
  cout<<"Enter the profit of each item\n";
  for(int i=1;i<=n;i++)
    cin>>profit[i];
  vector<vector<int>>dp(n+1,vector<int>(m+1,0));
  fillDpTable(weight,profit,dp,m,n);
  cout<<"\nDP Table is: \n";
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=m;j++)
      cout<<dp[i][j]<<" ";
    cout<<endl;
  }
  cout<<"\nMAX PROFIT = "<<dp[n][m]<<endl;
  cout<<"ANSWER: "<<getAns(profit,dp,m,n);
  return 0;  
}
