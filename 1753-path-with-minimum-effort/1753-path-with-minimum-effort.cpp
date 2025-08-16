class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue< pair<int,pair<int,int>>,vector <pair<int,pair<int,int>>> ,greater <pair<int,pair<int,int>>>>q;

        int n=heights.size();
        int m=heights[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        vector<vector<int>>dist(n,vector<int>(m,1e9));
        
        dist[0][0]=0;
        q.push({0,{0,0}});
        while(!q.empty()){ 
            int diff=q.top().first;
            int r=q.top().second.first;
            int c=q.top().second.second;
            q.pop();
            if(r==n-1 && c==m-1) return diff;
            for(int i=0;i<4 ;i++){
                int row=r+dr[i];
                int col=c+dc[i];
                if(row>=0 && row<n && col>=0 && col<m){
                    int neff=max(abs(heights[r][c]-heights[row][col]),diff);
                    if(neff < dist[row][col]){
                        dist[row][col]=neff;
                        q.push({neff,{row,col}});
                    }
                }
            }
        }
        return 0;
    }
};