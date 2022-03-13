/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        if (!head->next) {
            Node* newNode = new Node(head->val);
            newNode -> random = (head -> random) ? newNode : nullptr;
            return newNode;
        }
        vector<Node*> list, new_list;
        vector<int> random_idx;
        Node* h = head;
        while (h) {
            list.push_back(h);
            Node* newNode = new Node(h->val);
            new_list.push_back(newNode);
            h = h -> next;
        }
        h = head;
        while (h) {
            if (!h -> random) random_idx.push_back(-1);
            else {
                auto it = find(list.begin(), list.end(), h->random);
                random_idx.push_back(it-list.begin());
            }
            h = h -> next;
        }
        for (int i = 0; i < new_list.size()-1; i++) {
            h = new_list[i];
            h -> next = new_list[i+1];
            int idx = random_idx[i];
            h -> random = (idx != -1) ? new_list[idx] : nullptr;
        }
        h = h -> next;
        int idx = random_idx[new_list.size()-1];
        h -> random = (idx != -1) ? new_list[idx] : nullptr;

        return new_list[0];
    }
};
// @lc code=end

