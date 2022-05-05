/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack {
private:
    int tp;
    queue<int> q;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        tp = x;
    }
    
    int pop() {
        int n = q.size();
        int content = 0;
        for (int i = 0; i < n-1; i++) {
            content = q.front();
            q.push(content);
            tp = content;
            q.pop();
        }
        content = q.front();
        q.pop();
        return content;
    }
    
    int top() {
        return tp;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

