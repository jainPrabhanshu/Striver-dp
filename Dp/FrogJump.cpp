// there is a frog on the 1st step of an n stairs long staircase the frog wants to reach the nth stair height i is the height of the i 1 th stair if frog jumps from ith to jth stair the energy lost in the jump is given by absolute value of height i 1 height j 1 if the frog is on ith staircase he can jump either to i 1 th stair or to i 2 th stair your task is to find the minimum total energy used by the frog to reach from 1st stair to nth stair

#include <bits/stdc++.h> 
int jump(int ind,vector<int> &dp,vector<int> &heights){
    if(ind == 0){
        return 0;
    }
    if(dp[ind]!= -1 ){
        return dp[ind];
    }
    int left = jump(ind-1,dp,heights) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if(ind>1){
        right = jump(ind-2,dp,heights) + abs(heights[ind] - heights[ind - 2]);
    }
    return dp[ind] = min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1,-1);
    return jump(n-1,dp,heights);
}