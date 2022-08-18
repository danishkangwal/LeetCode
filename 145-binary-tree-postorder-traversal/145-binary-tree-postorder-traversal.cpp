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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        helper(root,postorder);
        return postorder;
    }
    void helper(TreeNode* root,vector<int> &postorder){
        if(!root)
            return;
        helper(root->left,postorder);
        helper(root->right,postorder);
        postorder.push_back(root->val);
    }
};