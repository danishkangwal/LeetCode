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
private:
    ListNode* head;
    int len(ListNode* head){
        int n = 0;
        while(head){
            n++;
            head = head->next;
        }
        return n;
    }
    TreeNode* dfs(int l,int r){
        if(l>r)
            return NULL;
        int mid = l + (r-l)/2;
        TreeNode* leftTree = dfs(l,mid-1);
        TreeNode* root = new TreeNode(head->val);
        root->left = leftTree;
        head = head->next;
        root->right = dfs(mid+1,r);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* _head) {
        int n = len(_head);
        head = _head;
        return dfs(0,n-1);
    }
};