/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution {
private:
    vector<bool> visited;
    vector<int> color;
    bool res = true;
    
    void DFS(vector<vector<int>>& graph, int node) {
        visited[node] = true;
        color[node] = max(color[node], 0); // set the unvisited node to color 0
        for (int adj : graph[node]) {
            if (visited[adj] && color[node] == color[adj])
                res = false;
            else if (!visited[adj]) {
                color[adj] = !color[node]; // set the adjacent node to different color
                DFS(graph, adj);
            }
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        visited.resize(n, false);
        color.resize(n, -1);
        for (int node = 0; node < n; node++) {
            if (!visited[node]) {
                DFS(graph, node);
            }
        }
        return res;
    }
};
// @lc code=end

