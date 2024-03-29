// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.
class Solution {
public:
    int coinChange(vector<int>& coins, int t) {
        vector<int> dp(t+1,INT_MAX-1);
        dp[0]=0;
        for(int i=0;i<t+1;i++){
            for(int j=0;j<coins.size();j++){
                if(i>=coins[j]){
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
                } 
            }
        }
        if(dp[t]<INT_MAX-1) 
            return dp[t];
        return -1;
    }
};