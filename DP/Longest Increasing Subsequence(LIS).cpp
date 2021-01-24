#include <bits/stdc++.h>
using namespace std;

void LISHelper(int *arr,int *lis,int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j]&&lis[i]<=lis[j])
                lis[i]=lis[j]+1;
        }
    }
    int high=INT_MIN;
    for(int i=0;i<n;i++)
        if(lis[i]>high)
            high=lis[i];
    cout<<"\nLength of longest increasing subsequence is: "<<high;
    cout<<"\n\nSubsequence is: ";
    string s;
    for(int i=n-1;i>=0;i--)
    {
        if(lis[i]==high)
        {
            s=to_string(arr[i])+s;
            s=" "+s;
            high--;
        }        
    }
    cout<<s;
}

int main() {
    int n;
    cout<<"\nEnter n: ";
    cin>>n;
    int arr[n],lis[n];
    cout<<"\nEnter n numbers:\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];    
        lis[i]=1;
    }
    LISHelper(arr, lis, n);
    return 0;
}
