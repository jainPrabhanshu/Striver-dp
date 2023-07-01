// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 class Solution {
public:
void solve(int col,int n,vector<vector<string>>&ans,vector<string>&board,                vector<int>&leftrow,vector<int>&lowerdiag,vector<int>&upperdiag)
{
      if(col==n)
      {
      ans.push_back(board);
      return;
      }

      for(int row=0;row<n;row++)
      {
         if(leftrow[row]==0 && lowerdiag[row+col]==0 && upperdiag[n-1+col-row]==0)
         {
             board[row][col]='Q';
             leftrow[row]=1;
             lowerdiag[row+col]=1;
             upperdiag[n-1+col-row]=1;
             solve(col+1,n,ans,board,leftrow,lowerdiag,upperdiag);
             board[row][col]='.';
             leftrow[row]=0;
             lowerdiag[row+col]=0;
             upperdiag[n-1+col-row]=0;
             
         }
      }

}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        vector<int>leftrow(n,0);       
        vector<int>lowerdiag(2*n-1,0);  
        vector<int>upperdiag(2*n-1,0); 
        solve(0,n,ans,board,leftrow,lowerdiag,upperdiag);
        return ans;
    }
};