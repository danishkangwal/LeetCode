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
    bool isSymmetric(TreeNode* left,TreeNode* right){
        if(!left and !right)
            return 1;
        if(!left or !right)
            return 0;
        if(left->val!=right->val)
            return 0;
        return isSymmetric(left->left,right->right) and isSymmetric(left->right,right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;

        return isSymmetric(root->left,root->right);
    }
};