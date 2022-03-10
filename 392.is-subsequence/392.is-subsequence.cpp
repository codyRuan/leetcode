/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, k = 0;
        while (i != t.size() && k != s.size()) {
            if (t[i] == s[k]) k++;
            i++;
        }
        return (k == s.size());
    }
};
// @lc code=end

