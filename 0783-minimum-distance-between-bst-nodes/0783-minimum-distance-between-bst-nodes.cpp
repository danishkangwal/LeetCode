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
    int minDistance = INT_MAX;
    int prev = -1;
    int minDiffInBST(TreeNode* root) {
        traversal(root);
        return minDistance;
    }
private:
    void traversal(TreeNode* root){
        if(!root)
            return;
        traversal(root->left);
        if(prev != -1)
            minDistance = min(minDistance,root->val - prev);
        prev = root->val;
        traversal(root->right);
    }
};