class DSU {
public:
    vector<int> parent, rank, size;
    DSU(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n);
        size.resize(n, 1);  
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int findUlPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUlPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUlPar(u);
        int ulp_v = findUlPar(v);

        if (ulp_u != ulp_v) {  
            if (rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];  
            } else if (rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            } else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
                size[ulp_u] += size[ulp_v];
            }
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n * n);

        
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 0) continue;
                int dr[4] = {-1, 0, 1, 0};
                int dc[4] = {0, 1, 0, -1};
                for (int k = 0; k < 4; ++k) {
                    int nrow = row + dr[k];
                    int ncol = col + dc[k];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = nrow * n + ncol;
                        ds.unionByRank(nodeNo, adjNodeNo);
                    }
                }
            }
        }

       
        int maxi = 0;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) continue;
                
                set<int> components;
                int dr[4] = {-1, 0, 1, 0};
                int dc[4] = {0, 1, 0, -1};
                
                
                for (int k = 0; k < 4; ++k) {
                    int nrow = row + dr[k];
                    int ncol = col + dc[k];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1) {
                        components.insert(ds.findUlPar(nrow * n + ncol));
                    }
                }

                
                int sizeTotal = 1;  
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                maxi = max(maxi, sizeTotal);
            }
        }

        
        for (int cellNo = 0; cellNo < n * n; ++cellNo) {
            maxi = max(maxi, ds.size[ds.findUlPar(cellNo)]);
        }

        return maxi;
    }
};