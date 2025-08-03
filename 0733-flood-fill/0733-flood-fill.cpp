class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& image, int color,int delrow[],int delcol[],vector<vector<int>>&ans,int inicolor){
        int n=image.size();
        int m=image[0].size();
        ans[row][col]=color;
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && image[nrow][ncol]==inicolor && ans[nrow][ncol]!=color){
                dfs(nrow,ncol,image,color,delrow,delcol,ans,inicolor);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int inicolor=image[sr][sc];
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        dfs(sr,sc,image,color,delrow,delcol,ans,inicolor);
            
        return ans;
    }
};