class Solution {
public:
    void bfs(int row,int col, vector<vector<int>>& vis,vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc] && grid[nr][nc]==1 ){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            if(grid[0][i]==1 && !vis[0][i])  bfs(0,i,vis,grid);
            if(grid[m-1][i]==1 && !vis[m-1][i])  bfs(m-1,i,vis,grid);
        }for(int i=0;i<m;i++){
            if(grid[i][0]==1 && !vis[i][0])  bfs(i,0,vis,grid);
            if(grid[i][n-1]==1 && !vis[i][n-1])  bfs(i,n-1,vis,grid);
        }int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    c+=1;
                }
            }
        }return c;
    }
};