class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> above(n, 0);
        
        for (int row = 0; row < m; row++) {
            vector<int> current(n, 0);
         
            for (int col = 0; col < n; col++) {
                if(row==0 && col==0) current[col]=grid[row][col];
                else{
                    int up=grid[row][col];
                    if(row>0) up+=above[col];
                    else up+=1e9;

                    int left=grid[row][col];
                    if(col>0) left+=current[col-1];
                    else left+=1e9;

                    current[col]=min(left,up);

                }

            }
            above = current;
        }

        return above[n - 1];    
    }
};