/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap;
        for (auto s : stones) max_heap.push(s);
        while (max_heap.size() > 1) {
            int top1 = max_heap.top();
            max_heap.pop();
            int top2 = max_heap.top();
            max_heap.pop();
            if (top2 < top1) max_heap.push(top1-top2);
        }
        if (max_heap.size() == 1) return max_heap.top();
        return 0;
    }
};
// @lc code=end

