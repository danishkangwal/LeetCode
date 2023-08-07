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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode* tmp = head;
        while(tmp and tmp->next){
            ListNode* a = new ListNode(gcd(tmp->val,tmp->next->val));
            a->next = tmp->next;
            tmp->next = a;
            tmp = a->next;
        }
        
        return head;
    }
};