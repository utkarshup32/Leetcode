/*class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1) return 1;
        return climbStairs(n-1)+climbStairs(n-2);
    }// runtime error
};*/
class Solution {
public:
    int climb(int n,vector<int>dp){
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }return dp[n];

    }
    int climbStairs(int n) {
          vector<int>dp(n+1,-1);
          return climb(n,dp);

    }
};