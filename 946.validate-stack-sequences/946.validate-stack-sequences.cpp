/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 */

// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> stk;
        vector<int>::iterator push = pushed.begin();
        for (int pop : popped) {
            if (find(stk.begin(), stk.end(), pop) == stk.end()) { // target is not in stack
                for (; push != pushed.end(); push++) { // push new element to stack
                    if (*push == pop) {
                        push++;
                        break;
                    }
                    else 
                        stk.push_back(*push);
                }
            }
            else {
                if (pop == stk.back()) // top is target
                    stk.pop_back(); 
                else return false;
            }
        }
        return true;
    }
};
// @lc code=end

