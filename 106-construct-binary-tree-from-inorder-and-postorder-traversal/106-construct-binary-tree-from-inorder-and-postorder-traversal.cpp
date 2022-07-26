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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //using a helper funtion with start and end parameter for both
        // inorder and postorder
        return buildTreeHelper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
    TreeNode* buildTreeHelper(vector<int> &inorder, vector<int> &postorder, int inS,int inE,int postS,int postE){
        //base condition
        if(inS > inE) return NULL;
        //rootData is at the end in postorder
        int rootData = postorder[postE];
        //rootIndex is index of rootData in inorder traversal
        int rootIndex = -1;
        for(int i = inS;i <= inE;i++){
            if(inorder[i] == rootData){
                rootIndex = i;
                break;
            }
        }
        //calculating both left and right value for inorder and postorder(needed for         // recursion)
        int linS = inS;
        int linE = rootIndex - 1;
        int lpostS = postS;
        int lpostE = linE - linS + lpostS;
        int rinS = rootIndex + 1;
        int rinE = inE;
        int rpostS = lpostE + 1;
        int rpostE = postE - 1;
        //creating a root node
        TreeNode* root = new TreeNode(rootData);
        //assigning left and right values using recursion
        root->left = buildTreeHelper(inorder,postorder,linS,linE,lpostS,lpostE);
        root->right = buildTreeHelper(inorder,postorder,rinS,rinE,rpostS,rpostE);
        return root;
    }
};