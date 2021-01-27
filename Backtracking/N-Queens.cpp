#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<string> &nQueens, int row, int col, int &n) 
{
    //check if the column had a queen before
    for (int i = 0; i != row; ++i)
        if (nQueens[i][col] == 'Q')
            return false;
    //check if the 45° diagonal had a queen before
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        if (nQueens[i][j] == 'Q')
            return false;
    //check if the 135° diagonal had a queen before
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
        if (nQueens[i][j] == 'Q')
            return false;
    return true;
}

void solveNQueens(vector<vector<string> > &res, vector<string> &nQueens, int row, int &n) 
{
    if (row == n) 
    {
        res.push_back(nQueens);
        return;
    }
    for (int col = 0; col != n; ++col)
        if (isValid(nQueens, row, col, n)) 
        {
            nQueens[row][col] = 'Q';
            solveNQueens(res, nQueens, row + 1, n);
            nQueens[row][col] = '.';
        }
}

int main() {
    int n;
    cout<<"Enter Number of queens: ";
    cin>>n;
    vector<vector<string> > res;
    vector<string> nQueens(n, string(n, '.'));
    solveNQueens(res, nQueens, 0, n);
    cout<<"\n\nTotal number of possible ways is "<<res.size()<<endl;
    for(int i=0;i<res.size();i++)
    {
        cout<<endl<<endl;
        for(int j=0;j<n;j++)
            cout<<res[i][j]<<endl;
    }
    return 0;
}


