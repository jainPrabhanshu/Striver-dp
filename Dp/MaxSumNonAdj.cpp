// you  are  given  an  array  list  of  n  integers  you  are  supposed  to  return  the  maximum  sum  of  the  subsequence  with  the  constraint  that  no  two  elements  are  adjacent  in  the  given  array  list

#include <bits/stdc++.h> 
int maximum(int ind,vector<int>&nums,vector<int>&dp ){
    if(ind <0 ){
        return 0;
    }
    if(ind == 0){
        return nums[ind];
    }
    if(dp[ind]!= -1){
        return dp[ind];
    }    
    int pick = nums[ind] + maximum(ind-2,nums,dp);
    int notPick = maximum(ind-1,nums,dp);
    return dp[ind]= max(pick,notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int>dp(n+1,-1);
    return maximum(n-1,nums,dp);
}