/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 */

// @lc code=start
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        int res = 0;
        vector<vector<int>> costs(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > pq;
        pq.push(make_tuple(-1, 0, 0));
        while (!visited[m-1][n-1] && !pq.empty()) {
            auto [cost, row, col] = pq.top();
            pq.pop();
            visited[row][col] = true;
            res = max(res, cost);
            for (int r = max(row-1, 0); r <= min(row+1, m-1); r++) {
                int ct = abs(heights[r][col] - heights[row][col]);
                if (costs[r][col] > ct && !visited[r][col]) {
                    pq.push(make_tuple(ct, r, col));
                    costs[r][col] = ct;
                }
            }
            for (int c = max(col-1, 0); c <= min(col+1, n-1); c++) {
                int ct = abs(heights[row][c] - heights[row][col]);
                if (costs[row][c] > ct && !visited[row][c]) {
                    pq.push(make_tuple(ct, row, c));
                    costs[row][c] = ct;
                }
            }
        }
        return res;
    }
};
// @lc code=end

