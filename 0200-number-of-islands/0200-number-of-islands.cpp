class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col){
        
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size())
            return;
        
        if(grid[row][col] == '0')
            return;

        grid[row][col] = '0';

        dfs(grid, row, col+1);
        dfs(grid, row, col-1);
        dfs(grid, row+1, col);
        dfs(grid, row-1, col);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
};