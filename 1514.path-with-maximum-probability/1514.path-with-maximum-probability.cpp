/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 */

// @lc code=start
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {  // store in adjacent list
            adj[edges[i][0]].push_back(make_pair(edges[i][1],succProb[i]));
            adj[edges[i][1]].push_back(make_pair(edges[i][0],succProb[i]));
        }
        queue<int> q;
        vector<double> prob(n,0);
        q.push(start);
        prob[start] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto nd : adj[node]){
                if (prob[nd.first] < prob[node] * nd.second){
                    prob[nd.first] = prob[node] * nd.second;
                    q.push(nd.first);
                }
            }
        }
        return prob[end];
    }
};
// @lc code=end

