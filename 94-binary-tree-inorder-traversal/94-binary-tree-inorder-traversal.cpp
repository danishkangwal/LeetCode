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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        
        vector<int> nodes;
        stack<TreeNode*> rem;
        
        while(root!=NULL || rem.size()!=0){
            while(root){
                rem.push(root);
                root = root->left;
            }
            root = rem.top();
            rem.pop();
            nodes.push_back(root->val);
            root = root->right;
        }
        
        return nodes;
    }
};