// You are given a triangular array/list 'TRIANGLE'. Your task is to return the minimum path sum to reach from the top to the bottom row.
// The triangle array will have N rows and the i-th row, where 0 <= i  < N will have i + 1 elements.
// You can move only to the adjacent number of row below each step. For example, if you are at index j in row i, then you can move to i or i + 1 index in row j + 1 in each step.
#include <bits/stdc++.h> 
int path(int i,int j,vector<vector<int>>& triangle, int n,vector<vector<int>> &dp){
	if(i==n-1){
		return triangle[n-1][j];
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	int down = triangle[i][j] + path(i+1,j,triangle,n,dp);
	int diagonal = triangle[i][j] + path(i+1,j+1,triangle,n,dp);
	return dp[i][j] = min(down,diagonal);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<vector<int>>dp(n,vector<int>(n,-1));
	return path(0,0,triangle,n,dp);
}