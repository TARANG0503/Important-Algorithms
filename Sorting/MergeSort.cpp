#include <iostream>
using namespace std;

void merge_(int *arr,int left,int mid,int right)
{
    int x=mid-left+1,y=right-mid;
    int a[x],b[y];
    for(int i=0;i<x;i++)
        a[i]=arr[left+i];
    for(int i=0;i<y;i++)
        b[i]=arr[mid+1+i];
    int i=0,k=left,j=0;
    while(i<x&&j<y)
    {
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            i++;
        }
        else
        {
            arr[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<x)
        arr[k++]=a[i++];
    while(j<y)
        arr[k++]=b[j++];
}

void mergeSort(int *arr,int left,int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge_(arr,left,mid,right);
    }
}

int main()
{
    int n;
    cout << "Enter n" << endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the numbers: "<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    mergeSort(arr,0,n-1);
    cout<<"Sorted Array:"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}
