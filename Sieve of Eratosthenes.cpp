#include <iostream>
using namespace std;

void sieve(int n)
{
  int isPrime[n+1];
  for(int i=0;i<=n;i++)
    isPrime[i]=1;
    
  for(int i=2;i*i<=n;i++)
    for(int j=i*i;j<=n;j=j+i)
      isPrime[j]=0;

  for(int i=2;i<=n;i++)
    if(isPrime[i])
      cout<<i<<endl;
}
int main() {
  cout<<"Enter n upto which prime numbers are to be found: ";
  int n;
  cin>>n;
  cout<<endl<<endl;
  sieve(n);
  return 0;
}
