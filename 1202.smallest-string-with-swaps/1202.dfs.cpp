/*
 * @lc app=leetcode id=1202 lang=cpp
 *
 * [1202] Smallest String With Swaps
 */

// @lc code=start
class Solution {
private:
    vector<int> indices;
    vector<bool> visited;
    vector<vector<int>> adjList;
    string componentString;

    void dfs(string &s, int idx) {
        indices.push_back(idx);
        componentString += s[idx];
        visited[idx] = true;
        for (auto adj : adjList[idx]) {
            if (!visited[adj]) 
                dfs(s, adj);
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        visited.resize(s.size(), false);
        adjList.resize(s.size());
        for (auto pair : pairs) {
            adjList[pair[0]].push_back(pair[1]);
            adjList[pair[1]].push_back(pair[0]);
        }

        for (int idx = 0; idx < s.size(); idx++) {
            if (!visited[idx]) {
                indices.clear();
                componentString.clear();
                dfs(s, idx);
                sort(componentString.begin(), componentString.end());
                sort(indices.begin(), indices.end());
                for (int i = 0; i < indices.size(); i++) 
                    s[indices[i]] = componentString[i];
            }
        }
        return s;
    }
};
// @lc code=end

