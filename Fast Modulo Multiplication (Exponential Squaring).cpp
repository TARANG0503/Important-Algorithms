#include <bits/stdc++.h>
using namespace std;

#define N 1000000007 // prime modulo value 
typedef long long ll;

ll exponential(ll num,ll pow)
{
  if(pow==0)
    return 1;
  if(pow==1)
    return num%N;
  ll r=exponential(num,pow/2);
  r=(r*r)%N;
  if(pow%2==0)
    return r;
  return ((num)%N*r)%N;
}

int main() {
  ll num,pow;
  cout<<"Enter the number: ";
  cin>>num;
  cout<<"Enter the power : ";
  cin>>pow;
  cout<<"\nANS: "<<exponential(num,pow);
}
