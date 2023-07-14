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
    ListNode* addTwoNumbers(ListNode* num1, ListNode* num2) {
        ListNode* head = new ListNode();
        ListNode* t = head;

        int carry = 0;
        while(num1 or num2 or carry){
            int sum = carry;
            if(num1){
                sum += num1->val;
                num1=num1->next;
            }
            if(num2){
                sum+=num2->val;
                num2=num2->next;
            }
            carry = sum/10;
            t->next = new ListNode(sum%10);
            t=t->next;
        }



        return head->next;
    }
};