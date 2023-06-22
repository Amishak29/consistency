class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> queue;
        int fresh = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                // count total fresh oranges
                if (grid[r][c] == 1) {
                    fresh++;
                }
                // add rotten orange to queue
                if (grid[r][c] == 2) {
                    queue.push({r, c});
                }
            }
        }
        int result = 0;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // now queue should have all initial rotten oranges
        while (!queue.empty() && fresh > 0) {
            int size = queue.size();
            // the rotting process should be done by all rotten oranges in a unit time
            for (int i = 0; i < size; i++) {
                // get row and col of rotten orange
                auto [r, c] = queue.front();
                queue.pop();
                // check all four directions for fresh orange
                for (int j = 0; j < 4; j++) {
                    int x = r + dirs[j][0];
                    int y = c + dirs[j][1];
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1) {
                        continue;
                    }
                    // make fresh orange rotten and add to queue
                    grid[x][y] = 2;
                    queue.push({x, y});
                    // decrement count of fresh oranges
                    fresh--;
                }
            }
            // increment unit of time when rotting is done by all oranges in the queue
            result++;
        }
        return fresh == 0 ? result : -1;
    }
};