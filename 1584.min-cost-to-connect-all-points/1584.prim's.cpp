/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */

// @lc code=start
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int visitedNodes = 0, res = 0;
        vector<bool> visited(n);
        vector<int> minDist(n, INT_MAX);

        minDist[0] = 0; // start node
        while (visitedNodes < n) {
            int cost = INT_MAX;
            int curr = -1;
            for (int node = 0; node < n; node++) {
                if (!visited[node] && minDist[node] < cost) {
                    cost = minDist[node];
                    curr = node;
                }
            }

            visited[curr] = true;
            res += cost;
            visitedNodes++;

            for (int node = 0; node < n; node++) {
                int dist = abs(points[curr][0] - points[node][0]) +
                        abs(points[curr][1] - points[node][1]);
                if (!visited[node] && dist < minDist[node]) 
                    minDist[node] = dist;
            }
        }
        return res;
    }
};
// @lc code=end

