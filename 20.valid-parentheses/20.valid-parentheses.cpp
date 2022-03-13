/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> par;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') par.push(ch);
            else {
                if (par.empty()) return false;
                char tp = par.top();
                if (int(ch) - int(tp) == 1 || int(ch) - int(tp) == 2) par.pop();
                else return false;
            }
        }
        if (!par.empty()) return false;
        return true;
    }
};
// @lc code=end

