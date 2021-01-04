#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,pattern;
  cout<<"Enter the string: ";
  cin>>s;
  cout<<"Enter the pattern: ";
  cin>>pattern;
  int n=s.length(),m=pattern.length(),c=0;
  for(int i=0;i<n;i++)
  {
    int k=i,j;
    for(j=0;j<m;j++)
    {
      c++;
      if(s[k]==pattern[j])
        k++;
      else
        break;
    }
    if(j==m)
    {
      cout<<"Pattern matched at "<<i<<" index"<<endl;
      cout<<"Number of comparisons is "<<c;
      return 0;
    }
  }
  cout<<"Pattern not matched";
  return 0;
}
