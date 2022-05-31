/*
 * @lc app=leetcode id=1461 lang=cpp
 *
 * [1461] Check If a String Contains All Binary Codes of Size K
 */

// @lc code=start
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int allnum = 1 << k;
        int allone = allnum - 1;
        int idx = 0;
        vector<bool> visited(allnum, false);

        for (int i = 0; i < s.size(); i++) {
            idx = ((idx << 1) & allone) | (s[i] - '0');

            if (i >= k - 1 && !visited[idx]) {
                visited[idx] = true;
                allnum--;
                if (!allnum) return true;
            }
        }

        return false;
    }
};
// @lc code=end

