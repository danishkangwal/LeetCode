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
    int postIdx;
    unordered_map<int, int> inorderIndexMap;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIdx = inorder.size()-1;
        for(int i = 0; i < inorder.size(); i++){
            inorderIndexMap[inorder[i]] = i;
        }
        
        return helper(postorder, 0, inorder.size()-1);
    }

    TreeNode* helper(vector<int>& postorder,int inStart,int inEnd) {
        if(inStart > inEnd) 
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[postIdx--]);
        int pivot = inorderIndexMap[root -> val];
        
        root -> right = helper(postorder, pivot+1, inEnd);
        root -> left  = helper(postorder, inStart, pivot-1);
        
        return root;
    }
};