/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution {
public:

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        set<string> nodes;
        for (auto equ : equations) {
            nodes.insert(equ[0]);
            nodes.insert(equ[1]);
        }
        int n = nodes.size();
        unordered_map<string, int> map;
        int c = -1;
        for (auto node : nodes)
            map[node] = ++c;
        vector<vector<double>> dist(n, vector<double>(n, DBL_MAX));
        for (int i = 0; i < equations.size(); i++) {
            string first = equations[i][0], second = equations[i][1];
            dist[map[first]][map[second]] = values[i];
            dist[map[second]][map[first]] = 1.0 / values[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (dist[j][i] + dist[i][k] <  DBL_MAX)
                        dist[j][k] = dist[j][i] * dist[i][k];
                }
            }
        }
        vector<double> res;
        cout << dist[map["a"]][map["b"]] << endl;
        for (auto qur : queries) {
            if (map.count(qur[0]) && map.count(qur[1]) && dist[map[qur[0]]][map[qur[1]]] != DBL_MAX)
                res.push_back(dist[map[qur[0]]][map[qur[1]]]);
            else 
                res.push_back(-1.0);
        }
        return res;
    }
};
// @lc code=end

