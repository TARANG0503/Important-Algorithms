#include <bits/stdc++.h>
using namespace std;

int kadane(int *arr,int n)
{
    int curr=0,max_so_far=INT_MIN;
    for(int i=0;i<n;i++)
    {
        curr+=arr[i];
        if(curr<arr[i])
            curr=arr[i];
        if(curr>max_so_far)
            max_so_far=curr;
    }
    return max_so_far;
}

int main() {
  cout<<"\nEnter n: ";
  int n;
  cin>>n;
  cout<<"\nEnter the numbers:\n";
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  cout<<"\n\nMaximum subarray sum is: "<<kadane(arr,n);
}
