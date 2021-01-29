#include <bits/stdc++.h>
using namespace std;

#define INF 1000;
int CoinChange(int *arr,int n,int amt)
{
    int dp[n+1][amt+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=0;
    for(int i=1;i<=amt;i++)
        dp[0][i]=INF;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=amt;j++)
        {
            if(arr[i-1]<=j)
                dp[i][j]=1+min(dp[i-1][j],dp[i][j-arr[i-1]]);
            else
                dp[i][j]=dp[i-1][j];
        }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=amt;j++)
            if(dp[i][j]>=1000)
                cout<<"∞ ";
            else
                cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    if(dp[n][amt]>=1000)
        return -1;
    return dp[n][amt];
}
int main() {
    int n,amt;
    cout<<"\nEnter number of coins: ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the denominations of coins: \n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"\nEnter the amont: ";
    cin>>amt;
    cout<<"\nDP Table:\n";
    int ans=CoinChange(arr,n,amt);
    if(ans>-1)
        cout<<"\nMinimum coins required to form this amount is: "<<ans;
    else
        cout<<"\nAmount can't be formed";
    return 0;
}
