/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjList(n+1);
        vector<int> dist(n+1, INT_MAX);
        // built adjacency list (time, dest)
        for (auto pair : times) {
            adjList[pair[0]].push_back(make_pair(pair[2], pair[1]));
        }
        // start from node k
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, k));
        // Dijkstra's algo
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int time = p.first;
            int source = p.second;

            for (auto adj : adjList[source]) {
                int adjTime = adj.first;
                int adjSource = adj.second;
                if (dist[source] + adjTime < dist[adjSource]) {
                    dist[adjSource] = dist[source] + adjTime;
                    pq.push(adj);
                }
            }
        }
        // get the ans
        int res = INT_MIN;
        for (int i = 1; i < n+1; i++) {
            res = max(res, dist[i]);
        }

        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end

