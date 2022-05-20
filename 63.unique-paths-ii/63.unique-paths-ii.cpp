/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
    int DFS(vector<vector<int>>& obstacleGrid, vector<vector<int>>& numOfPath, int row, int col) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (row == m-1 && col == n-1 && !obstacleGrid[row][col]) return numOfPath[row][col] = 1;
        else if (row == m-1 && col == n-1 && obstacleGrid[row][col]) return numOfPath[row][col] = 0;
        if (numOfPath[row][col] != -1) return numOfPath[row][col];

        int path = 0;
        if (row + 1 < m && !obstacleGrid[row+1][col])
            path += DFS(obstacleGrid, numOfPath, row+1, col);
        if (col + 1 < n && !obstacleGrid[row][col+1])
            path += DFS(obstacleGrid, numOfPath, row, col+1);
        
        return numOfPath[row][col] = path;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0]) return 0;
        
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> numOfPath(m, vector<int>(n, -1));

        int path = DFS(obstacleGrid, numOfPath, 0, 0);

        return numOfPath[0][0];
    }
};
// @lc code=end

