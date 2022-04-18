/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) : k(k){
        for (auto n : nums) minHeap.push(n);
        while (minHeap.size() > k) minHeap.pop();
    }
    
    int add(int val) {
        minHeap.push(val);
        while (minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

