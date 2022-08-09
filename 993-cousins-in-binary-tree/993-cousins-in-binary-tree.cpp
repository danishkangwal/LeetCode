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
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root)
            return false;
        
        queue<TreeNode *> rem;
        rem.push(root);
        while(rem.size()){
            int n = rem.size();
            int bool1 = 0,bool2 = 0;
            for(int i = 0;i < n;i++){
                TreeNode *tmp = rem.front();
                rem.pop();
                if(tmp->left && tmp->right)  
                {
                    if((tmp->left->val == x && tmp->right->val == y) || (tmp->left->val == y && tmp->right->val == x))
                        return false;
                }
                if(tmp->val==x)bool1 = 1;
                if(tmp->val==y)bool2 = 1;
                if(bool1 && bool2)return true;
                if(tmp->left)rem.push(tmp->left);
                if(tmp->right)rem.push(tmp->right);
            }
        }
        
        return false;
    }
};