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
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).second;
    }
    pair<int,int> helper(TreeNode *root){
        if(!root) return{0,0};
        
        pair<int,int> left = helper(root->left);
        pair<int,int> right = helper(root->right);
        
        return {1+max(left.first,right.first) , max({left.first+right.first,left.second,right.second})};
    }
};