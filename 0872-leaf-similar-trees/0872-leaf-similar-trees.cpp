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
        
        vector<int> seq1;
        vector<int> seq2;
        helper(root1,seq1);        
        helper(root2,seq2);
        if(seq1.size() != seq2.size())
            return 0;
        for(int i =0;i < seq1.size();i++){
            if(seq1[i] != seq2[i])
                return 0;
        }
        return 1;
    }
private:
    void helper(TreeNode* root,vector<int>& a){
        if(!root)
            return;
        if(!root->left && !root->right)
            a.push_back(root->val);
        helper(root->left,a);
        helper(root->right,a);
    }
};