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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return;
        
        stack<ListNode *> st;
        int size = 0;
        ListNode *temp = head;
        while(temp!=NULL){
            st.push(temp);
            size++;
            temp = temp->next;
        }
        
        ListNode* node = head;
        for (int j = 0;j < size/2; j++)
        {
            ListNode *top = st.top();
            st.pop();
            top->next = node->next;
            node->next = top;
            node = node->next->next;
        }
        node->next = NULL;
    }
};