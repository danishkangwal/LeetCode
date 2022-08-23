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
    bool isPalindrome(ListNode* head) {
        ListNode *prev = NULL, *fast = head, *slow = head;
        while(fast && fast->next) {		
        	fast = fast->next->next;
        	ListNode *tmp = slow;
        	slow = slow->next;
        	tmp->next = prev;
        	prev = tmp;
        }
        if(fast != NULL) {
        	slow = slow->next;
        }
        while(prev && slow){
            if(prev->val != slow->val){
                return false;
            }
            prev = prev->next;
            slow = slow->next;
        }
        return true;
    }
};