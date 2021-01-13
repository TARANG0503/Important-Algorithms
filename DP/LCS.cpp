#include <bits/stdc++.h>
using namespace std;
string getLCS(vector<vector<int>>dp,string s1,string s2)
{
  string ans="";
  int i=s1.length(),j=s2.length();
  while(i>0&&j>0)
  {
    if(dp[i][j]==dp[i-1][j])
      i--;
    else if(dp[i][j]==dp[i][j-1]) 
      j--;
    else
    {
      ans=s1[i-1]+ans;
      i--;
      j--;
    }   
  }
  return ans;
}

void print(vector<vector<int>>vec)
{
  for(int i=0;i<vec.size();i++)
  {
    for(int j=0;j<vec[i].size();j++)
      cout<<vec[i][j]<<"  ";
    cout<<endl;
  }
}

int main() {
  string s1,s2;
  cout<<"Enter first string: ";
  cin>>s1;
  cout<<"Enter second string: ";
  cin>>s2;
  int l1=s1.length(),l2=s2.length();
  vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
  for(int i=1;i<=l1;i++)
  {
    for(int j=1;j<=l2;j++)
    {
      if(s1[i-1]==s2[j-1])
        dp[i][j]=dp[i-1][j-1]+1;
      else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  cout<<"\nLength of longest common subsequence is: "<<dp[l1][l2]<<endl;
  cout<<"\nLongest common subsequence is: "<<getLCS(dp,s1,s2)<<endl<<endl;
  cout<<"DP Table:\n";
  print(dp);
}
