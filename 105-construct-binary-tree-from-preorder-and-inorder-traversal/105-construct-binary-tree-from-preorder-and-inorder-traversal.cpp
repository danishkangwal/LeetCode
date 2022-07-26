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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //using a helper function with start and end parameter for both 
        // preorder and inorder
        return buildTreeHelper(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int preS, int preE, int inS, int inE){
        //base condition
        if(preS > preE) return NULL;
        //root is in start of preorder
        int rootData = preorder[preS];
        //rootIndex is the index of rootData in inorder traversal
        int rootIndex = -1;
        for(int i = inS;i <= inE;i++){
            if(inorder[i] == rootData){
                rootIndex = i;
                break; //no need to check further
            }
        }
        //calculating value for left and right parts of traversals(needed to use             // recurion)
        int lPreS = preS + 1;
        int lInS = inS;
        int lInE = rootIndex - 1;
        int lPreE = (lInE - lInS + lPreS);
        int rPreS = lPreE + 1;
        int rPreE = preE;
        int rInS = rootIndex + 1;
        int rInE = inE;
        //creating a new root node
        TreeNode *root = new TreeNode(rootData);
        //using recursion assigning both left and right child
        root->left = buildTreeHelper(preorder,inorder,lPreS,lPreE,lInS,lInE);
        root->right = buildTreeHelper(preorder,inorder,rPreS,rPreE,rInS,rInE);
        return root;
    }
};