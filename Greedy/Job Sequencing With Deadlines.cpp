#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cout<<"Enter number of jobs: ";
  cin>>n;
  vector<int>profit(n,0);
  vector<int>time(n,0);
  for(int i=0;i<n;i++)
  {
    cout<<"\nJOB "<<i+1<<endl;
    cout<<"Enter profit: ";
    cin>>profit[i];
    cout<<"Enter waiting time: ";
    cin>>time[i];
  }
  //sort in decreasing order of profit
  int t=0;
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(profit[i]<profit[j])
      {
        swap(profit[i],profit[j]);
        swap(time[i],time[j]);
      }
    }
    if(time[i]>t)
      t=time[i];
  }
  int p=0,c=0;
  vector<int>slots(t,0);
  cout<<endl<<"Profits: ";
  for(int i=0;i<n;i++)
  {
    for(int j=time[i]-1;j>=0;j--)
    {
      if(slots[j]==0)
      {
        slots[j]=profit[i];
        p+=profit[i];
        cout<<profit[i]<<" ";
        c++;
        break;
      }
    }
    if(c==t)
      break;
  }
  cout<<"\nTotal profit is "<<p;
  return 0;
}
