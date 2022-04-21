/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
class MyHashSet {
private:
    set<int> m;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        m.insert(key);
    }
    
    void remove(int key) {
        m.erase(key);
    }
    
    bool contains(int key) {
        auto it = find(m.begin(), m.end(), key);
        if (it != m.end()) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

