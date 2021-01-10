#include <bits/stdc++.h>
using namespace std;

void printParenthesis(int i, int j, int n,vector<vector<int>>bracket, char &name) 
{ 
    if (i == j) 
    { 
      cout << name++; 
      return; 
    }   
    cout << "("; 
    printParenthesis(i, bracket[i][j], n, bracket, name); 
    printParenthesis(bracket[i][j] + 1, j, n, bracket, name); 
    cout << ")"; 
} 
int main() {
  cout<<"Enter no.of matrices: ";
  int n;
  cin>>n;
  int dimensions[n+1];
  cout<<"Enter the dimensions of matrices:\n";
  for(int i=0;i<=n;i++)
    cin>>dimensions[i];
  vector<vector<int>>costTable(n+1,vector<int>(n+1,0));
  vector<vector<int>>kTable(n+1,vector<int>(n+1,0));
  for(int l=2;l<=n;l++)
  {
    for(int i=1;i<=n-l+1;i++)
    {
      int j=l+i-1;
      costTable[i][j]=INT_MAX;
      for(int k=i;k<j;k++)
      {
        int cost=costTable[i][k]+costTable[k+1][j]+dimensions[i-1]*dimensions[k]*dimensions[j];
        if(costTable[i][j]>cost)
        {
          costTable[i][j]=cost;
          kTable[i][j]=k;
        }
      }
    }    
  }
  cout<<endl<<endl;
  cout<<"Cost Table for matrix multiplication: \n";
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      cout<<costTable[i][j]<<" ";
    cout<<endl;
  }
  cout<<endl<<endl;
  cout<<"K Table for matrix multiplication: \n";
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      cout<<kTable[i][j]<<" ";
    cout<<endl;
  }
  char ch='A';
  cout<<endl<<endl;
  cout<<"Parenthesis for matrix multiplication: \n";
  printParenthesis(1, n, n, kTable, ch);
  return 0;
}
