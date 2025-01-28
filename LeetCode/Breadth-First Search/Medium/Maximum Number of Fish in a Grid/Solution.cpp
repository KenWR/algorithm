// Breadth-First Search

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        size_t m = grid.size(), n = grid[0].size();
        deque<pair<int, int>> dq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int maximumFish = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] && visited[i][j] == false) {
                    dq.push_back(make_pair(i, j));
                    visited[i][j] = true;

                    int catchedFish = 0;
                    while (!dq.empty()) {
                        pair<int, int> top = dq.front();
                        int row = top.first;
                        int col = top.second;
                        dq.pop_front();
                        catchedFish += grid[row][col];

                        if (row && grid[row - 1][col] && visited[row - 1][col] == false) {
                            dq.push_back(make_pair(row - 1, col));
                            visited[row - 1][col] = true;
                        }
                        if (row != m - 1 && grid[row + 1][col] && visited[row + 1][col] == false) {
                            dq.push_back(make_pair(row + 1, col));
                            visited[row + 1][col] = true;
                        }
                        if (col && grid[row][col - 1] && visited[row][col - 1] == false) {
                            dq.push_back(make_pair(row, col - 1));
                            visited[row][col - 1] = true;
                        }
                        if (col != n - 1 && grid[row][col + 1] && visited[row][col + 1] == false) {
                            dq.push_back(make_pair(row, col + 1));
                            visited[row][col + 1] = true;
                        }
                    }

                    maximumFish = max(maximumFish, catchedFish);
                } 
            }
        }
        return maximumFish;
    }
};