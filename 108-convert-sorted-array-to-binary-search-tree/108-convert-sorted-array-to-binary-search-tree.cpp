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
    using iter = vector<int>::const_iterator;
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums.begin(),nums.end());
    }
private:
    TreeNode* helper(iter left, iter right){
        if(left>=right)
            return nullptr;
        iter mid = left + (right-left)/2;
        TreeNode *root = new TreeNode(*mid);
        
        root->left = helper(left,mid);
        root->right = helper(mid+1,right);
        
        return root;
    }
};