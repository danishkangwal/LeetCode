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
private:
    ListNode* merge(ListNode** left,ListNode** right){
        if(*left==NULL){
            return *right;
        }
        if(*right==NULL){
            return *left;
        }
        ListNode* head = new ListNode();
        ListNode* tail = head;
        ListNode* t1 = *left;
        ListNode* t2 = *right;
        while(t1 and t2){
            if(t1->val < t2->val){
                tail->next = t1;
                t1 = t1->next;
            }
            else{
                tail->next = t2;
                t2 = t2->next;
            }
            tail = tail->next;
        }
        while(t1){
            tail->next = t1;
            tail = tail->next;
            t1 = t1->next;
        }
        while(t2){
            tail->next = t2;
            tail = tail->next;
            t2 = t2->next;
        }
        return head->next;
    }
    void print(ListNode* head){
        while(head){
            cout<<head->val;
            head = head-> next;
        }
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        
        if(lists.size()==1){
            return lists[0];
        }
        
        int mid = lists.size()/2;
        
        vector<ListNode*> left(lists.begin(),lists.begin()+mid);
        vector<ListNode*> right(lists.begin()+mid,lists.end());
        
        
        ListNode* leftSorted = leftSorted = mergeKLists(left);
        ListNode* rightSorted = rightSorted = mergeKLists(right);
        
        return merge(&leftSorted,&rightSorted);
    }
};