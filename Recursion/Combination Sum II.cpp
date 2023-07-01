// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.
class Solution {
public:
    void findComb(vector<int>& arr,int target,vector<vector<int>>&ans,vector<int>&temp,int index){
        if(target==0){
            ans.push_back(temp);
            return ;
        }
        for(int i=index;i<arr.size();i++){
            if(i>index && arr[i]==arr[i-1])continue;
        
            if(target<arr[i]){
                break;
            }
            temp.push_back(arr[i]);
            findComb(arr,target-arr[i],ans,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        findComb(candidates,target,ans,temp,0);
        return ans;
    }
};