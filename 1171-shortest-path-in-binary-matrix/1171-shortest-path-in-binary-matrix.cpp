class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        
        if (n == 1) {
            return 1;
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        
        int pathLength = 1;

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            int levelSize = q.size();
            pathLength++;
            
            for (int i = 0; i < levelSize; ++i) {
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;

                for (int j = 0; j < 8; ++j) {
                    int newR = r + dr[j];
                    int newC = c + dc[j];

                    if (newR == n - 1 && newC == n - 1) {
                        return pathLength;
                    }

                    if (newR >= 0 && newR < n && newC >= 0 && newC < n && grid[newR][newC] == 0) {
                        grid[newR][newC] = 1; 
                        q.push({newR, newC});
                    }
                }
            }
        }
        
        return -1;
    }
};