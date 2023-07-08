// You have been given an N*M matrix filled with integer numbers, find the maximum sum that can be obtained from a path starting from any cell in the first row to any cell in the last row.
// from a cell in a row you can move to another cell directly below that row or diagonally below left or right so from a particular cell row col we can move in three directions 
#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix) {
    int n=matrix.size(),m=matrix[0].size();
    if(n==1) {
        return *max_element(matrix[0].begin(),matrix[0].end());
    }
    int ans=INT_MIN;
    vector<vector<int>>dp(n,vector<int>(m));
    dp[0]=matrix[0];
    for(int i=1;i<n;i++) {
        for(int j=0;j<m;j++) {
            int dl=(j>0?dp[i-1][j-1]:INT_MIN);
            int up=dp[i-1][j];
            int dr=(j+1<m?dp[i-1][j+1]:INT_MIN);
            dp[i][j]=matrix[i][j]+max({dl,up,dr});
            if(i==n-1) {
                ans=max(ans,dp[i][j]);
            }
        }
    }
    return ans;
}