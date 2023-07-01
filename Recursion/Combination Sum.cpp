// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
// frequency
//  of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

class Solution {
public:
    void CombinationSum(vector<int>& arr, int target,vector<vector<int>>&ans,vector<int>&temp,int index){
        if(index==arr.size()){
            if(target == 0){
            ans.push_back(temp);
            }
            return;
        }
        if(target>=arr[index]){
            temp.push_back(arr[index]);
            CombinationSum(arr,target-arr[index],ans,temp,index);
            temp.pop_back();
        }
        CombinationSum(arr,target,ans,temp,index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        CombinationSum(candidates,target,ans,temp,0);
        return ans;
    }
};