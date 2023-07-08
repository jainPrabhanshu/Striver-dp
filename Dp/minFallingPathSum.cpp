// You have been given a square array 'VEC' of integers of size 'N' rows and 'N' columns. Your task is to find the minimum sum of a falling path through the square array. The number of rows and columns in the given array will be the same.
// A falling path starts at any element in the first row and chooses one element from each row.  The next row's choice must be in a column that is different from the previous row's column by at most one.
#include <bits/stdc++.h> 
int minPath(int i,int j,vector<vector<int>> &vec, int n,vector<vector<int>> &dp){
    if(j<0 || j>=n){
        return 1e9;
    }
    if(i==0){
        return vec[0][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int d = vec[i][j] + minPath(i-1,j,vec,n,dp);
    int dl = vec[i][j] + minPath(i-1,j-1,vec,n,dp);
    int dr = vec[i][j] + minPath(i-1,j+1,vec,n,dp);
    return dp[i][j] = min(d,min(dl,dr));
}
int minFallingPathSum(vector<vector<int>> &vec, int n) {
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    int minimum = 1e9;
    for(int j=0;j<n;j++){
        minimum = min(minimum,minPath(n-1,j,vec,n,dp));
    }
    return minimum;
}