/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
class Solution {
    int getDist(vector<vector<int>>& matrix, vector<vector<int>>& longDist, 
                int row, int col) {
        if (longDist[row][col] != -1) return longDist[row][col];
        int m = matrix.size(), n = matrix[0].size();
        int dist = 1;

        for (int r = max(0, row-1); r <= min(m-1, row+1); r++)
            if (matrix[row][col] < matrix[r][col])
                dist = max(dist, 1 + getDist(matrix, longDist, r, col));
        for (int c = max(0, col-1); c <= min(n-1, col+1); c++)
            if (matrix[row][col] < matrix[row][c])
                dist = max(dist, 1 + getDist(matrix, longDist, row, c));

        return longDist[row][col] = dist;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> longDist(m, vector<int>(n, -1));
        int res = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int dist = getDist(matrix, longDist, i, j);
                res = max(res, dist);
            }
        }
        
        return res;
    }
};
// @lc code=end

