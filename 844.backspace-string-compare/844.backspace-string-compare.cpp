/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        size_t found = s.find("#");
        while (found != string::npos) {
            if (found != 0)
                s.erase(--found,2);
            else 
                s.erase(found,1);
            found = s.find("#");
        }
        found = t.find("#");
        while (found != string::npos) {
            if (found != 0)
                t.erase(--found,2);
            else 
                t.erase(found,1);
            found = t.find("#");
        }
        return s == t;
    }
};
// @lc code=end

