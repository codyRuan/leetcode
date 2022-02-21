/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return head;
        ListNode* firstNode = head;
        ListNode* secondNode = head -> next;
        ListNode* nextHead = secondNode -> next;
        secondNode -> next = firstNode;
        head = secondNode;
        firstNode -> next = swapPairs(nextHead);
        return head;
    }
};
// @lc code=end

