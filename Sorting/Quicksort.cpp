#include <bits/stdc++.h>
using namespace std;

int partitionQuick(int *arr,int l,int r)
{
    int pivot=arr[r];
    int i=l-1,j=r-1;
    for(int k=l;k<=j;k++)
    {
        if(arr[k]<=pivot)
        {
            i++;
            swap(arr[k],arr[i]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;

}
void quicksort(int *arr,int l,int r)
{
    if(l<r)
    {
        int q = partitionQuick(arr,l,r);
        quicksort(arr,l,q-1);
        quicksort(arr,q+1,r);
    }
}

int main()
{
    int n,k;
    cout<<"Enter numbers of number to be entered: \n";
    cin>>n;
    int arr[n];
    cout<<"Enter numbers to be sorted\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quicksort(arr,0,n-1);
    cout<<"\nSorted Array: \n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
