#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,pattern;
  cout<<"Enter the string: ";
  cin>>s;
  cout<<"Enter the pattern: ";
  cin>>pattern;
  int n=s.length(),m=pattern.length(),c=0;
  pattern="a"+pattern;
  vector<int>lps(m+1,0);
  for(int i=2,j=1;i<=m;i++)
  {
    if(pattern[i]==pattern[j])
      lps[i]=j++;
    else
      j=1;
  }
  //Print lps/pi table:
  // for(int i=0;i<=m;i++)
  //   cout<<lps[i]<<" ";
  int j=0;
  for(int i=0;i<n;i++)
  {
    if(s[i]==pattern[j+1])
      j++;
    else
    {
      if(j!=0)
        i--;
      j=lps[j];
    }
    c++;
    if(j==m)
    {
      cout<<"Pattern matched at "<<i-m+1<<" index"<<endl;
      cout<<"Number of comparisons is "<<c;
      return 0;
    }
  }
  cout<<"Pattern not matched";
  return 0;
}
