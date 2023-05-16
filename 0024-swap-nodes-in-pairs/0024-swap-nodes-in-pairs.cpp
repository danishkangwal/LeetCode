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
        if(head==NULL or head->next==NULL)
            return head;
        ListNode* t1 = head;
        ListNode* t2 = head->next;
        
        
        t1->next = t2->next;
        t2->next = t1;
        if(t1==head)
            head = t2;
        head->next->next = swapPairs(head->next->next);
            
        return head;
    }
};