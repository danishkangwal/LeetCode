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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        return helper(root).second;
    }
    pair<int,bool> helper(TreeNode* root){
        if(!root) return {0,true};
        
        pair<int,bool> left = helper(root->left);
        pair<int,bool> right = helper(root->right);
        if(abs(left.first-right.first)>1) return {-1,false};
        
        return {1+max(left.first,right.first), left.second && right.second};
    }
};