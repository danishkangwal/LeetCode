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
    int countNodes(TreeNode* root) {
        int ans = 0;
        helper(root,ans);
        return ans;
    }
private:
    void helper(TreeNode* root, int &ans){
        if(root == NULL)
            return;
        ans++;
        helper(root->left,ans);
        helper(root->right,ans);
    }
};