// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 class Solution {
public:
    void permutations(int index,vector<int> &nums,vector<vector<int>>&ans){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            permutations(index+1,nums,ans);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        permutations(0,nums,ans);
        return ans;
    }
};