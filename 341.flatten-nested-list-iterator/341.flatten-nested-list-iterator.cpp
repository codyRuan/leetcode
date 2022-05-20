/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<NestedInteger*> stk;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size()-1; i >=0; i--) {
            stk.push_back(&nestedList.at(i));
        }
    }
    
    int next() {
        int num = stk.back()->getInteger();
        stk.pop_back();
        return num;
    }
    
    bool hasNext() {
        while (!stk.empty()) {
            NestedInteger* cur = stk.back();
            if (cur->isInteger()) {
                return true;
            }
            else {
                stk.pop_back();
                vector<NestedInteger>& vec = cur->getList();
                for (int i = vec.size()-1; i >= 0; i--)
                    stk.push_back(&vec.at(i));
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

