// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int i, int n){
        if(i == n-1)
            return dp[i] = 0;

        if(dp[i] != -1)
            return dp[i];
            
        int minimum = 1e9;
        for(int j = 1; j <= nums[i]; j++){
            if(i+j < n){
                int count = 1 + solve(nums, dp, i+j, n);
                minimum = min(minimum, count);
            }
            
        }
        
        return dp[i] = minimum;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, dp, 0, n);
    }
};