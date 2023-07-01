// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            if(dp[i-1]>0){
                dp[i]=max(dp[i-1]-1,nums[i]); 
            }
            else{
                dp[i]=-1;
            }
        }
        if(dp[nums.size()-1]!=-1){
            return true;
        }
        return false;
    }
};