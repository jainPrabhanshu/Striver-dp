// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<int> dp(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            vector<int> arr(n, 0);
            arr[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    arr[j] = 2 + dp[j-1];
                } else {
                    arr[j] = max(dp[j], arr[j-1]);
                }
            }
            dp = arr;
        }
        return dp[n-1];
    }
};