/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int start = 0, end = 0;
        vector<bool> visited(26,false);
        vector<int> res;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (visited[c-'a']) continue;
            end = max(end, int(s.rfind(c)));
            if (i == end) {
                res.push_back(end-start+1);
                start = i+1;
            }
        }
        return res;
    }
};
// @lc code=end

