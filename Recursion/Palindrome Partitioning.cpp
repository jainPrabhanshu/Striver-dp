// Given a string s, partition s such that every 
// substring
//  of the partition is a 
// palindrome
// . Return all possible palindrome partitioning of s.

class Solution {
public:
    bool isPalindrome(string&s,int l,int r){
        while(l<r){
           if( s[l]!=s[r]){
               return false;
           }
            l++;
            r--;
        }
           return true;
            
    }
    
    void palinPartition(string& s,int start,vector<string>& temp,vector<vector<string>>& ans){
        
        int n = s.length();
        if(start==n){
            ans.push_back(temp);
        }
        for(int i = start;i<n;i++){
            if(isPalindrome(s,start,i)){
                temp.push_back(s.substr(start,i-start+1));
                palinPartition(s,i+1,temp,ans);
                temp.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        palinPartition(s,0,temp,ans);
        return ans;
    }
}; 
