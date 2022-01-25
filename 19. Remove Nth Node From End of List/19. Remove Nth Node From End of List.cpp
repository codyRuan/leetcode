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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *h = head;
        int len = 0;
        while (h) {
            len++;
            h = h -> next;
        }
        if (n == len) return head -> next;
        h = head;
        for (int i = 1; i < len-n; i++){
            h = h -> next;
        }
        ListNode *dlt = h -> next;
        h -> next = dlt -> next;
        return head;
    }
    };