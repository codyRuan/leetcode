/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> stk;
        int res = 0;
        for (auto s : ops) {
            if (s ==  "C")
                stk.pop_back();
            else if (s == "D")
                stk.push_back(stk.back()*2);
            else if (s == "+") {
                int first = stk.back();
                stk.pop_back();
                int second = stk.back();
                stk.push_back(first);
                stk.push_back(first+second);
            }
            else
                stk.push_back(stoi(s));
        }
        for (auto num : stk) res += num;
        return res;
    }
};
// @lc code=end

