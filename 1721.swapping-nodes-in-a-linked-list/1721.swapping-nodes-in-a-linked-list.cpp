/*
 * @lc app=leetcode id=1721 lang=cpp
 *
 * [1721] Swapping Nodes in a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nul
 lptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode* h = head;
        while (--k) h = h -> next;
        ListNode* node1 = h;
        ListNode* node2 = head;
        while (h -> next) {
            node2 = node2 -> next;
            h = h -> next;
        }
        swap(node1->val, node2->val);
        return head;
    }
};
// @lc code=end

