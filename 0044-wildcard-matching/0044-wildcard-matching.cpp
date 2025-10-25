class Solution {
public:
    /*bool f(int i,int j,string& s, string& p,vector<vector<int>>&dp){
        if(i<0 && j<0) return true;
        if(j<0 && i>=0 ) return false;
        if(i<0 && j>=0){
            for(int i1=0;i1<=j;i1++){
                if(p[i1]!='*') return false;
            }return true;
        }if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?') return dp[i][j]=f(i-1,j-1,s,p,dp);
        if(p[j]=='*') return dp[i][j]=f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp);
        return dp[i][j]=false;

    }*/
    bool isMatch(string text, string pattern) {
        int n1 = text.size();
        int n2 = pattern.size();
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
        dp[0][0] = true;
        
        for (int j = 1; j <= n2; j++) {
            if (pattern[j - 1] == '*') dp[0][j] = dp[0][j - 1];
        }
        for (int i = 1; i <= n1; i++) {
            dp[i][0] = false;
        }
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (text[i - 1] == pattern[j - 1] || pattern[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pattern[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n1][n2];
    }
};