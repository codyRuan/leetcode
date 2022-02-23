/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<int,Node*> nodelist;
        if (!node)
            return nullptr;
        return traceNode(node, nodelist);
    }
    Node* traceNode(Node* node, map<int,Node*> &nodelist) {
        auto itr = nodelist.find(node->val);
        if (itr == nodelist.end()) {
            Node* newNode = new Node(node->val);
            vector<Node*> n = node->neighbors;
            nodelist.insert(make_pair(node->val,newNode));
            for (int i = 0 ; i < n.size(); i++){
                newNode -> neighbors.push_back(traceNode(n[i], nodelist));
            }
            return newNode;
        }
        else {
            return itr->second;
        }
    }
};
// @lc code=end

