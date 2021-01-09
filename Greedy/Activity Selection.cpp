#include <bits/stdc++.h>
using namespace std;
int main() {
  cout<<"Enter number of activities ";
  int n;
  cin>>n;
  int arr[n][3];
  for(int i=0;i<n;i++)
  {
    cout<<"\nActivity "<<i+1<<"\n";
    cout<<"Start time: ";
    cin>>arr[i][0];
    cout<<"End time: ";
    cin>>arr[i][1];
    arr[i][2]=i+1;
  }
  //Bubble Sort
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(arr[i][1]>arr[j][1])
      {
        swap(arr[i][1],arr[j][1]);
        swap(arr[i][0],arr[j][0]);
        swap(arr[i][2],arr[j][2]);
      }
    }
  }
  // Activites Selection
  int last=arr[0][1];
  cout<<"\nSelected Activities are: "<<arr[0][2]<<" ";
  for(int i=0;i<n;i++)
  {
    if(arr[i][0]>=last)
    {
      cout<<arr[i][2]<<" ";
      last=arr[i][1];
    }
  }
  return 0;  
}
