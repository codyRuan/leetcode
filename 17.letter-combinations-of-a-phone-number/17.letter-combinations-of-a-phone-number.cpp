/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
    unordered_map<char, string> phoneMap = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, 
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };
    vector<string> res = {""};
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        for (char digit : digits) {
            vector<string> tmp;
            for (char candicate : phoneMap[digit]) {
                for (string s : res) {
                    tmp.push_back(s+candicate);
                }
            }
            res.swap(tmp);
        }
        return res;
    }
    
};
// @lc code=end

