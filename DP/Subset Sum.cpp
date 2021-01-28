#include <bits/stdc++.h>
using namespace std;

int subsetSum(int *arr,int n,int sum)
{
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=true;
    for(int i=1;i<=sum;i++)
        dp[0][i]=false;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=sum;j++)
        {
            bool temp=false;
            if(arr[i-1]<=j)
                temp=dp[i-1][j-arr[i-1]];
            dp[i][j]=(dp[i-1][j]||temp);
        }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[n][sum];
}
int main() {
    int n,sum;
    cout<<"\nEnter n: ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the numbers: \n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"\nEnter the sum: ";
    cin>>sum;
    cout<<"\nDP Table:\n";
    if(subsetSum(arr,n,sum))
        cout<<"\nSum possible";
    else
        cout<<"\nSum NOT possible";
    return 0;
}
