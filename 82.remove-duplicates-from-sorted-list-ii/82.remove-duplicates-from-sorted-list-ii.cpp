/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        int preval = -1000;
        ListNode *dummyhead = new ListNode();
        ListNode *ptr = dummyhead;
        while (head && head->next) {
            if (head->val != preval && head->val != head->next->val) {
                ptr->next = head;
                ptr = ptr->next;
            }
            preval = head->val;
            head = head->next;
        }
        if (head->val != preval) ptr->next = head;
        else ptr->next = nullptr;
        return dummyhead->next;
    }
};
// @lc code=end

