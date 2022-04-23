/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
class MyHashMap {
private:
    vector<pair<int,int> > m;
    auto findKey(int key) {
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->first == key)
                return it;
        }
        return m.end();
    }
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        auto itr = findKey(key);
        if (itr != m.end())
            itr->second = value;
        else 
            m.push_back(make_pair(key,value));
    }
    
    int get(int key) {
        auto itr = findKey(key);
        if (itr != m.end()) 
            return itr->second;
        return -1;
    }
    
    void remove(int key) {
        auto itr = findKey(key);
        if (itr != m.end())
            m.erase(itr);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

