/*
 * @lc app=leetcode id=1641 lang=cpp
 *
 * [1641] Count Sorted Vowel Strings
 */

// @lc code=start
class Solution {
public:
    int countVowelStrings(int n) {
        int a = 1, e = 1, i = 1, o = 1, u = 1;
        while (--n) {
            o += u;
            i += o;
            e += i;
            a += e;
        }
        return a + e + i + o + u;
    }
};
// @lc code=end

