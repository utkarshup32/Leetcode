class Solution {
private:
    int timer = 1;

    void dfs(int node, int parent, vector<int> &vis,
             vector<vector<int>> &adj, int tin[], int low[],
             vector<vector<int>> &bridges) {

        vis[node] = 1;
        tin[node] = low[node] = timer++;

        for (int nbr : adj[node]) {
            if (nbr == parent) continue;

            if (!vis[nbr]) {
                dfs(nbr, node, vis, adj, tin, low, bridges);
                low[node] = min(low[node], low[nbr]);

                if (low[nbr] > tin[node]) {
                    bridges.push_back({node, nbr});
                }
            } else {
                low[node] = min(low[node], tin[nbr]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto& conn : connections) {
            int u = conn[0], v = conn[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;

        dfs(0, -1, vis, adj, tin, low, bridges);
        return bridges;
    }
};