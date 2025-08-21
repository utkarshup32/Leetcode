class DisjointSet {
public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    
    void unionBySize(int u,int v){
        u = findParent(u);
        v = findParent(v);
        if(u==v) return;
        if(size[u]<size[v]){
            parent[u] = v;
            size[v] += size[u];
        }
        else{
            parent[v] = u;
            size[u] += size[v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int len = connections.size();
        DisjointSet ds(n);
        if(len<n-1) return -1;
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            ds.unionBySize(u,v);
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) count++;
        }
        
        return count-1;
    }
};