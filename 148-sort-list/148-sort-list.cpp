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
    #define pb push_back
    ListNode* sortList(ListNode* head) {
        if(head==NULL)return NULL;
        vector<int> v;
        ListNode *temp = head;
        while(temp!=NULL){
            v.pb(temp->val);
            temp = temp->next;
        }
        sort(v.begin(),v.end());
        int index = 0;
        temp = head;
        for(auto i:v){
            temp->val = v[index++];
            temp = temp->next;
        }
        return head;
    }
};