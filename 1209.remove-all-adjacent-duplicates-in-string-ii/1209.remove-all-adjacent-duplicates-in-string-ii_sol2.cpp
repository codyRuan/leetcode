/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int, char>> stk = {{0, '#'}};
        string res;

        for (auto ch : s) {
            if (stk.back().second != ch)
                stk.push_back({1, ch});
            else if (++stk.back().first == k)
                stk.pop_back();
        }

        for (auto p : stk) {
            res.append(p.first, p.second);
        }

        return res;
    }
};
// @lc code=end

