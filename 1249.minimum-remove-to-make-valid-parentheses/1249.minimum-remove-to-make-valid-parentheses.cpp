/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<char> stk;
        string res;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '(') stk.push_back(ch);
            else if (ch == ')') {
                if (!stk.empty()) stk.pop_back();
                else continue;
            }
            res += ch;
        }
        while (!stk.empty()) {
            size_t pos = res.rfind("(");
            res.erase(pos,1);
            stk.pop_back();
        }
        return res;
    }
};
// @lc code=end

