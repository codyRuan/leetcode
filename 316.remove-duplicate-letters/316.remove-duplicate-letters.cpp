/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26,0);
        vector<bool> visited(26,false);
        string res = "";
        for (char c : s) {
            count[c-'a']++;
        }
        for (char c : s) {
            count[c-'a']--;
            if (visited[c-'a']) continue;
            while (c < res.back() && count[res.back()-'a']) {
                visited[res.back()-'a'] = false;
                res.pop_back();
            }
            visited[c-'a'] = true;
            res += c;
        }
        return res;
    }
};
// @lc code=end

