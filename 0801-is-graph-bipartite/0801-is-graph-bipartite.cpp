class Solution {
private:                                                                                     
    bool bfs(int node,int n,vector<int>&color,vector<vector<int>>& graph){
        color[node]=0;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int i=q.front();
            q.pop();
            for(auto k:graph[i]){
                if(color[k]==-1){
                    color[k]=!color[i];
                    q.push(k);
                }else if(color[k]==color[i])  return false;
            }
        }return true;
    }                                                    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(i,n,color,graph)) return false;
            }    
        }return true;
    }
};