// you have been given a number of stairs initially you are at the 20th stair and you need to reach the nth stair each time you can either climb one step or two steps you are supposed to return the number of distinct ways in which you can climb from the 0th step to nth step

#include <bits/stdc++.h> 
#define MOD 1000000007

int countDistinctWays(int nStairs) {
   
    if(nStairs == 0) {
        return 1;
    }
    if(nStairs == 1) { 
        return 1;
    }
    int left = 1;
    int right = 1;

    // step-3
    int ans;
    for(int i = 2; i <= nStairs; i++) {
        ans = (left + right) % MOD;
        right = left;
        left = ans;
    }

    return ans;
}