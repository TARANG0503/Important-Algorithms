#include <bits/stdc++.h>
using namespace std;
int editDistance(string s, string t)
{
    int n=s.length(),m=t.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=i;
    for(int j=1;j<=m;j++)
        dp[0][j]=j;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i-1]==t[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]))+1;
    return dp[n][m];
}
int main() {
    string s,t;
    cout<<"\nEnter string1: ";  
    cin>>s;
    cout<<"\nEnter string2: ";
    cin>>t;
    cout<<"\nMin n0.of operations required to convert string1 to string2 :"<<editDistance(s,t);
    return 0;
}
