#include <bits/stdc++.h>
using namespace std;

//array implementation of max heap
class MaxHeap{
  public:
  vector<int>newArr;
  MaxHeap()
  {
    //makes the array 1 indexed
    newArr.push_back(INT_MIN);
  }
  void insert(vector<int>&arr,int n,int pos)
  {
    arr.push_back(n);
    int parent=pos/2;
    while(parent>=1&&arr[pos]>arr[parent])
    {
      swap(arr[pos],arr[parent]);
      pos=parent;
      parent=pos/2;
    }
  }
  int remove(vector<int>&arr,int end)
  {
    if(end == 1)
      return arr[1];
    swap(arr[1],arr[end]);

    int target=1,l,r,temp=1;
    do{
      if(arr[target]<arr[temp])
      {
        swap(arr[target],arr[temp]);
        target=temp;
      }

      l=2*target<end?2*target:0;
      r=2*target+1<end?2*target+1:0;    
      if(arr[l]>arr[r])
        temp=l;
      else
        temp=r;    
    }while(arr[target]<arr[temp]);

    return arr[end];
  }
  void print(vector<int>arr)
  {
    for(int i=1;i<arr.size();i++)
      cout<<arr[i]<<" ";
  }
};
int main() {
  MaxHeap h;  
  vector<int>arr=h.newArr;
  int n,k;
  cout<<"Enter the value of n: ";
  cin>>n;
  cout<<"\nEnter the n numbers\n";
  int pos=1;
  while(n--)
  {
    int num;
    cin>>num;
    h.insert(arr,num,pos++);
  }
  cout<<"Sorted Array: ";
  cout<<endl;
  while(--pos)
    h.remove(arr,pos);
  h.print(arr);
}
