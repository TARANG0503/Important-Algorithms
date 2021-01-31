#include <iostream>
using namespace std;

#define N 1000000007

// C(n,r)=C(n-1,r)+C(n-1,r-1)
int nCr(int n, int r)
{
    int dp[n+1][r+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
        
    for(int i=1;i<=r;i++)
        dp[0][i]=0;
        
    for(int i=1;i<=n;i++)
        for(int j=1;j<=r;j++)
            dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%N;
            
    return dp[n][r];
}
int main() {
    int n,r;
    cout<<"\nEnter value of n and r\n";
    cin>>n>>r;
    cout<<endl<<n<<"C"<<r<<" = "<<nCr(n,r);  
}
