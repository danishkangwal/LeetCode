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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        vector<int> curr;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        s1.push(root);
        while(s1.size() || s2.size()){
            if(s1.size()){
                while(s1.size()){
                    TreeNode *top = s1.top();
                    s1.pop();
                    curr.push_back(top->val);
                    if(top->left)s2.push(top->left);
                    if(top->right)s2.push(top->right);
                }
                ans.push_back(curr);
                curr.clear();
            }
            if(s2.size()){
                while(s2.size()){
                    TreeNode *top = s2.top();
                    s2.pop();
                    curr.push_back(top->val);
                    if(top->right)s1.push(top->right);
                    if(top->left)s1.push(top->left);
                }
                ans.push_back(curr);
                curr.clear();
            }
        }
        
        return ans;
    }
};