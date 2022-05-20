/*
 * @lc app=leetcode id=1192 lang=cpp
 *
 * [1192] Critical Connections in a Network
 */

// @lc code=start
class Solution {
    void DFS(vector<vector<int>>& adjList, vector<int>& visited, vector<int>& low,
             int parent, vector<vector<int>> &res, int node, int time) {
        low[node] = visited[node] = ++time;
        for (int adj : adjList[node]) {
            if (adj == parent) continue;
            if (visited[adj] == 0) {
                DFS(adjList, visited, low, node, res, adj, time);
                low[node] = min(low[node], low[adj]);
                if (low[adj] > visited[node])
                    res.push_back({adj, node});
            }
            else {
                low[node] = min(low[node], visited[adj]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n);
        vector<int> visited(n, 0);
        vector<int> low(n);
        vector<vector<int>> res;
        int time = 0;
        for (auto pair : connections) {
            adjList[pair[0]].push_back(pair[1]);
            adjList[pair[1]].push_back(pair[0]);
        }
        for (int i = 0; i < n; i++)
            DFS(adjList, visited, low, -1, res, i, time);
        
        return res;
    }
};
// @lc code=end

