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
class myComparator
{
public:
    int operator() (const ListNode* p1, const ListNode* p2)
    {
        return p1->val > p2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (int i = lists.size()-1; i >= 0; i--){
            auto a = lists[i];
            if (!a) lists.erase(lists.begin() + i);
        }
        if (lists.size() < 1) return NULL;
        
        priority_queue <ListNode*, vector<ListNode*>, myComparator> pq;
        for (auto itr = lists.begin(); itr != lists.end(); itr++) pq.push(*itr);
        ListNode *head = new ListNode();
        ListNode *tmp = head;
        while (!pq.empty()){
            ListNode *etxmin = pq.top();
            tmp -> next = etxmin;
            tmp = tmp -> next;
            pq.pop();
            if (etxmin -> next) pq.push(etxmin -> next);
        }
        return head -> next;
    }
};