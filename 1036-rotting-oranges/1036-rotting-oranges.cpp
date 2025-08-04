#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int cntFresh = 0;


        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    cntFresh++;
                }
            }
        }

        if (cntFresh == 0) return 0; 

        int minutes = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;

            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front();
                q.pop();

                for (int d = 0; d < 4; ++d) {
                    int nrow = r + dr[d];
                    int ncol = c + dc[d];

                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1) {
                        grid[nrow][ncol] = 2;
                        q.push({nrow, ncol});
                        cntFresh--;
                        rotted = true;
                    }
                }
            }

            if (rotted) minutes++;
        }

        return cntFresh == 0 ? minutes : -1;
    }
};
