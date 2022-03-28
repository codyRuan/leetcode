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
        vector<int> last(26,-1);
        for (int i = 0; i < s.size(); i++) {
            last[s[i]-'a'] = i;
        }
        vector<int> res;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i]-'a']);
            if (i == end) {
                res.push_back(end-start+1);
                start = i+1;
            }
        }
        return res;
    }
};
// @lc code=end

