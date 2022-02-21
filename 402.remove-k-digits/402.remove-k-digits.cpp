/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() < 1)
            return "0";
        if (k <= 0){
            string s = del_zero(num);
            if (s.size() < 1)
                return "0";
            else 
                return s;
        }
        // if (num.size() <= 1) // k >= 1
        //     return "0";
        for (int i = 0; i < num.size()-1; i++){
            if (num[i] > num[i+1]){
                num.erase(num.begin() + i);
                return removeKdigits(num, --k);
            }
        }
        num.erase(num.end() - 1);
        return removeKdigits(num, --k);
    }
    string del_zero(string num){
        int numofzero = 0;
        for (int i = 0; i < num.size(); i++){
            if (num[i] == '0')
                numofzero ++;
            else
                break;
        }
        num.erase(0, numofzero);
        return num;
    }
};
// @lc code=end

