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
        vector<int> inorder;
        while(head!=NULL){
            inorder.emplace_back(head->val);
            head = head->next;
        }
        return constructBST(inorder);
    }
private:
    using iter = vector<int>::const_iterator;
    TreeNode* constructBSTHelper(iter left,iter right){
        if(left>=right)
            return NULL;
        iter mid = left + (right-left)/2;
        TreeNode* root = new TreeNode(*mid);
        
        root->left = constructBSTHelper(left,mid);
        root->right = constructBSTHelper(mid+1,right);
        
        return root;
    }
    TreeNode* constructBST(vector<int> &a){
        if(a.size()==0)
            return NULL;
        return constructBSTHelper(a.begin(),a.end());
    }
};