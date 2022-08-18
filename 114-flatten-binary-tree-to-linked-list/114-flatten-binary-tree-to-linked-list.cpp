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
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        
        vector<int> preorder;
        helper(root,preorder);
        // TreeNode *newRoot = new TreeNode(preorder[0]);
        TreeNode* prev = root;
        for(int i = 1;i < preorder.size();i++){
            TreeNode *newNode = new TreeNode(preorder[i]);
            prev->right = newNode;
            prev = prev->right;
        }
        root->left = NULL;
    }
    void helper(TreeNode* root,vector<int> &preorder){
        if(!root){
            return;
        }
        preorder.push_back(root->val);
        helper(root->left,preorder);
        helper(root->right,preorder);

    }
};