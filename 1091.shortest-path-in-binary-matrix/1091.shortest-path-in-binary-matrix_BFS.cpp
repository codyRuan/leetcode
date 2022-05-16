/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0]) return -1;
        int n = grid.size();
        queue<pair<int,int>> q; // pair<row,col>

        q.push({0,0});
        grid[0][0] = 1; // set the start node distant to 1
        // Dijkstra's algo
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if (row == n-1 && col == n-1) return grid[n-1][n-1];
            for (int i = max(0,row-1); i <= min(n-1,row+1); i++) {
                for (int j = max(0,col-1); j <= min(n-1,col+1); j++) {
                    if (!grid[i][j]) {
                        grid[i][j] = grid[row][col] + 1;
                        q.push({i,j});
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end

