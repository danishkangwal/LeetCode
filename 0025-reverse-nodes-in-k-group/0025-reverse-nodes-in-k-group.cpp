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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy,*curr = head,*next;
        int count = 0;
        while(curr){
            count++;
            curr=curr->next;
        }
        
        while(count>=k){
            curr = prev->next;
            next = curr->next;
            for(int i=0;i<k-1;i++){
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            
            count-=k;
            prev=curr;
        }
        
        return dummy->next;
    }
};