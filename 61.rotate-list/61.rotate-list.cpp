/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head -> next) return head;

        int len = 1, prev_idx;
        ListNode* h = head;
        ListNode* new_head;
        while (h -> next) {
            len ++;
            h = h -> next;
        }
        h -> next = head;
        k = k % len;
        prev_idx = len - k - 1;
        h = head; //initialize
        for (int i = 0; i < prev_idx; i++) h = h -> next;
        new_head = h -> next;
        h -> next = nullptr;
        return new_head;
    }
};
// @lc code=end

