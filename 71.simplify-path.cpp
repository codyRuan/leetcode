/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> splt = split(path, '/');
        vector<string> stk;
        string res;
        for (int i = 0; i < splt.size(); i++) {
            string str = splt[i];
            if (str == "..") {
                if (!stk.empty()) stk.pop_back();
            }
            else if (str == ".") continue;
            else stk.push_back(str);
        }
        
        for (string str : stk) {
            res += ("/"+str);
        }
        if (res.empty()) res += "/";
        return res;
    }

    const vector<string> split(const string &str, const char &delimiter) {
        vector<string> res;
        stringstream ss(str);
        string token;
        while (getline(ss, token, delimiter)) {
            if (!token.empty()) res.push_back(token);
        }
        return res;
    }
};
// @lc code=end

