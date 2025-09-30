class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size();

        vector<int> prev = matrix[0];
        vector<int>curr(n,0);

        for(int i=1;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                int u=matrix[i][j]+prev[j];
                
                int ld=matrix[i][j];
                if(j-1>=0) ld+=prev[j-1];
                else ld+=1e8;
                
                int rd=matrix[i][j];
                if(j+1<n) rd+=prev[j+1];
                else rd+=1e8;

                curr[j]=min(rd,min(u,ld));

            }prev=curr;

        }
        int mini=1e8;
        for(int j=0;j<n;j++){
            mini=min(mini,prev[j]);
        }return mini;

    }
};