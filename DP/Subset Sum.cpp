#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int *arr,int n,int sum)
{
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=true;
    for(int i=1;i<=sum;i++)
        dp[0][i]=false;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=sum;j++)
            dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i]];
    return dp[n+1][sum+1];
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
    cout<<endl;
    if(subsetSum(arr,n,sum))
    cout<<"Sum possible";
    else
    cout<<"Sum NOT possible";
    return 0;
}
