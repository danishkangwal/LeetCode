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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> pq;
        ListNode* temp;
        for(auto& list:lists){
            temp = list;
            while(temp){
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        ListNode* head = new ListNode();
        temp = head;
        while(pq.size()){
            temp->next = new ListNode(pq.top());
            temp = temp->next;
            pq.pop();
        }
        return head->next;
    }
};