#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(vector<int>& stones, int ind, int k, unordered_map<int,int>& mpp, vector<vector<int>>& dp) {
        if (ind == stones.size() - 1) return true; // reached last stone
        if (dp[ind][k] != -1) return dp[ind][k];

        bool ans = false;

        // Try jump of k-1
        if (k > 1 && mpp.count(stones[ind] + k - 1)) 
            ans |= f(stones, mpp[stones[ind] + k - 1], k - 1, mpp, dp);

        // Try jump of k
        if (k > 0 && mpp.count(stones[ind] + k)) 
            ans |= f(stones, mpp[stones[ind] + k], k, mpp, dp);

        // Try jump of k+1
        if (mpp.count(stones[ind] + k + 1)) 
            ans |= f(stones, mpp[stones[ind] + k + 1], k + 1, mpp, dp);

        return dp[ind][k] = ans;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();

        unordered_map<int,int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[stones[i]] = i; // map stone position -> index
        }

        // dp[n][n], since max jump length cannot exceed n
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        // Frog starts at index 0, with a required first jump of 1
        if (!mpp.count(1)) return false; // no stone at pos=1
        return f(stones, mpp[1], 1, mpp, dp);
    }
};
