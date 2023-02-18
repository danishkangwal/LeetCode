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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        TreeNode* temp1 = root->left;
        TreeNode* temp2 = root->right;
        root->left=NULL;root->right=NULL;
        if(temp1)
            root->right = invertTree(temp1);
        if(temp2)
            root->left = invertTree(temp2);
        return root;
    }
};