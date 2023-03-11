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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        
        ListNode* lt = findMid(head);
        if(lt->next == NULL){
            return new TreeNode(lt->val);
        }
        ListNode* right = lt->next->next;
        int data = lt->next->val;
        lt->next = NULL;
        
        TreeNode* root = new TreeNode(data);
        TreeNode* left = sortedListToBST(head); 
        root->left = left;
        root->right = sortedListToBST(right);
        return root;
    }
private:
    ListNode* findMid(ListNode* head){
        if(head==NULL)
            return NULL;
        ListNode *slow = head,*fast = head,*prev = head;
        while(fast and fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return prev;
    }
};