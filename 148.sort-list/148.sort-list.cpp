/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return mergeList(left, right);
    }
    ListNode* mergeList(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode();
        ListNode* tmp = dummy;
        while (left && right) {
            if (left->val < right->val) {
                tmp->next = left;
                left = left->next;
            }
            else {
                tmp->next = right;
                right = right->next;
            }
            tmp = tmp->next;
        }
        if (left) tmp->next = left;
        else tmp->next = right;
        return dummy->next;
    }

    ListNode* getMid(ListNode* head) {
        ListNode* midPrevious = nullptr;
        while (head && head->next) {
            midPrevious = (midPrevious == nullptr) ? head : midPrevious->next;
            head = head->next->next;
        }
        ListNode* mid = midPrevious->next; // right head
        midPrevious->next = nullptr; // left tail
        return mid;
    }
};
// @lc code=end

