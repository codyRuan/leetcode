/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 */

// @lc code=start
class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> stk;
        map<int,int> par;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') stk.push_back(i);
            else {
                par[stk.back()] = i;
                stk.pop_back();
            }
        }
        int start_ptr = 0, end_ptr = -1, score = 0;
        while (end_ptr != s.size()-1) {
            end_ptr = par[start_ptr];
            score += getScore(s, par, start_ptr, end_ptr);
            start_ptr = end_ptr+1;
        }
        return score;
    }
    int getScore(string& s, map<int,int>& par, int start, int end) {
        if (start+1 == end) return 1;
        int start_ptr = start+1, end_ptr = -1, score = 0;
        while (end_ptr != end-1) {
            end_ptr = par[start_ptr];
            score += getScore(s, par, start_ptr, end_ptr);
            start_ptr = end_ptr+1;
        }
        return 2*score;
    }
};
// @lc code=end

