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
    void traversal(TreeNode* root,vector<int>& a){
        if(!root)
            return;
        traversal(root->left,a);
        a.push_back(root->val);
        traversal(root->right,a);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> a;
        traversal(root,a);
        sort(a.begin(),a.end());
        int mini = INT_MAX;
        for(int i = 0;i < a.size()-1;i++){
            mini = min(mini,abs(a[i]-a[i+1]));
        }
        return mini;
    }
};