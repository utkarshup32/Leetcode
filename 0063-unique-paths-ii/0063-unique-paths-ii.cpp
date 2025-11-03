class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<int>dp(n,0);
        for(int i=0;i<m;i++){
            vector<int>p(n,0);
            for(int j=0;j<n;j++){
                if (i == 0 && j == 0) {
                    if ( obstacleGrid[0][0] == 0)
                        p[j] =  1; 
                    else
                        p[j] =  0; 
                }
                else if ( obstacleGrid[i][j] == 1) {
                    p[j] = 0;
                }else {
                    int up=0,left=0;
                    if(i>0) up=dp[j];
                    if(j>0) left=p[j-1];
                    p[j]=up+left;
                 }

            }dp=p;
        }return dp[n-1];
    }
};