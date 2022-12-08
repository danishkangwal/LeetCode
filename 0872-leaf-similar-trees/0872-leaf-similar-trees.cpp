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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)
            return 1;
        if(!root1 || !root2)
            return 0;
        
        string a,b;
        helper(root1,a);        
        helper(root2,b);
        return a==b;
    }
private:
    void helper(TreeNode* root,string &s){
        if(!root)
            return;
        if(!root->left && !root->right)
            s += to_string(root->val)+'#';
        helper(root->left,s);
        helper(root->right,s);
    }
};