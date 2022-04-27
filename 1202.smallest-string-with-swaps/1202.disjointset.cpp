/*
 * @lc app=leetcode id=1202 lang=cpp
 *
 * [1202] Smallest String With Swaps
 */

// @lc code=start
class DisjointSet {
private:
    vector<int> root;
    vector<int> rank;
public:
    DisjointSet(int size) : root(size), rank(size) {
        for (int i = 0; i < size; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }
    int find(int node) {
        if (node == root[node])
            return node;
        
        return root[node] = find(root[node]);
    }
    void Union(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);
        if (root1 == root2) return;
        else {
            if (rank[root1] >= rank[root2]) {
                root[root2] = root1;
                rank[root1] += rank[root2];
            }
            else {
                root[root1] = root2;
                rank[root2] += rank[root1];
            }
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        DisjointSet ds(s.size());
        map<int, vector<int>> components;

        for (auto pair : pairs) { 
            ds.Union(pair[0], pair[1]);
        }

        for (int i = 0; i < s.size(); i++) {
            components[ds.find(i)].push_back(i);
        }

        for (auto component : components) {
            vector<char> chars;
            vector<int> nodes = component.second;
            for (auto node : nodes) {
                chars.push_back(s[node]);
            }
            sort(chars.begin(), chars.end());
            sort(nodes.begin(), nodes.end());
            for (int i = 0; i < nodes.size(); i++) {
                s[nodes[i]] = chars[i];
            }
        }
        return s;
    }
};
// @lc code=end

