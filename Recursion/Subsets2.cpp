// Given an integer array nums that may contain duplicates, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.
class Solution {
public:
    void findSub(int index,vector<int>& nums,vector<vector<int>> &ans,vector<int> &temp){
        ans.push_back(temp);
        for(int i= index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            findSub(i+1,nums,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        findSub(0,nums,ans,temp);
        return ans;
    }
};
