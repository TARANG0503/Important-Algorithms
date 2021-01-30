#include <bits/stdc++.h>
using namespace std;
bool binarySearch(int *arr,int low,int high,int k)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==k)
            return true;
        else if(arr[mid]>k)
            return binarySearch(arr,low,mid-1,k);
        else
            return binarySearch(arr,mid+1,high,k);
        }
    return false;
}
int main()
{
    cout <<"\nEnter n\n";
    int n;
    cin>>n;
    cout<<"\nEnter the elements\n";
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"\nEnter the element to be found\n";
    int k;
    cin>>k;
    sort(arr,arr+n);
    if(binarySearch(arr,0,n-1,k))
        cout<<"\nElement found";
    else
        cout<<"\nElement not found";
    return 0;
}
