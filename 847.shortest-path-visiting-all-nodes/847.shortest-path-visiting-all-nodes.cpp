/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 */

// bitmask
// @lc code=start
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int result = 0, n = graph.size();
        queue<tuple<int,int,int>> q;
        vector<vector<int>> visited(n, vector<int>(1<<n));
        for (int i = 0; i < n; i++) {   // initialize
            visited[i][1<<i] = true;
            q.push(make_tuple(i,1<<i,0));
        }

        while (!q.empty()) {
            auto [idx, bitmask, distance] = q.front(); q.pop();
            if (bitmask == (1<<n)-1) {
                result = distance;
                break;
            }
            for (auto node : graph[idx]) {
                int mask = bitmask | (1<<node);
                if (!visited[node][mask]) {
                    visited[node][mask] = true;
                    q.push(make_tuple(node,mask,distance+1));
                }
            }
        }
        return result;
    }
};
// @lc code=end

