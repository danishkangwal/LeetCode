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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return 1;
        stack<TreeNode*> lStack;
        stack<TreeNode*> rStack;
        lStack.push(root->left);
        rStack.push(root->right);
        while(lStack.size() and rStack.size()){
            TreeNode* left = lStack.top();
            TreeNode* right = rStack.top();
            lStack.pop();rStack.pop();
            if(!left and !right)
                continue;
            if(!left || !right || left->val!=right->val)
                return 0;
            lStack.push(left->right);lStack.push(left->left);
            rStack.push(right->left);rStack.push(right->right);
        }
        return lStack.empty() and rStack.empty();
    }
};