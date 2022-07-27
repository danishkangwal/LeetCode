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
    //rootIdx is the root of the Binary Tree
    int rootIdx = 0;
    unordered_map<int,int> inorderIndexMap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //entering inorder value-index pair in map
        for(int i = 0;i < inorder.size();i++){
            inorderIndexMap[inorder[i]] = i;
        }
        
        return helper(preorder,0,inorder.size()-1);
    }
    TreeNode* helper(vector<int> &preorder,int left,int right){
        if(left > right)
            return NULL;
        int rootData = preorder[rootIdx];
        int pivot = inorderIndexMap[rootData];
        rootIdx++;
        TreeNode *root = new TreeNode(rootData);
        
        //calling recursive function on both sides
        root->left = helper(preorder,left,pivot-1);
        root->right = helper(preorder,pivot+1,right);
        
        return root;
    }
};