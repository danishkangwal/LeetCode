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
    bool isValidBST(TreeNode* root) {
        
        return valid(root);
    }
private:
    bool valid(TreeNode* root,long left = LONG_MIN,long right = LONG_MAX){
        if(!root)
            return true;
        if(!(root->val > left && root->val < right))
            return false;
        
        return (valid(root->left,left,root->val) && valid(root->right,root->val,right));
    }
};