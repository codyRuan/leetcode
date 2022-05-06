/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> stk;
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (stk.empty()) stk.push_back(make_pair(s[i], 1));
            else {
                auto tp = stk.back();
                if (s[i] == tp.first && tp.second+1 == k)
                    for (int t = 0; t < k-1; t++)
                        stk.pop_back();
                else if (s[i] == tp.first && tp.second+1 != k)
                    stk.push_back(make_pair(s[i], tp.second+1));
                else
                    stk.push_back(make_pair(s[i], 1));
            }
        }

        for (auto p : stk)
            res += p.first;

        return res;
    }
};
// @lc code=end

