class Solution {
public:
    int ways(int ind,vector<int>& coins,int T, vector<vector<int>>&dp){
        if(ind==0) return (T%coins[0]==0);

        if(dp[ind][T]!=-1) return  dp[ind][T];

        int nottake = ways(ind-1,coins,T,dp);
        int take=0;
        if(coins[ind]<=T) take=ways(ind,coins,T-coins[ind],dp);

        return dp[ind][T]=take + nottake;

    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return ways(coins.size()-1,coins,amount,dp);
    }
};