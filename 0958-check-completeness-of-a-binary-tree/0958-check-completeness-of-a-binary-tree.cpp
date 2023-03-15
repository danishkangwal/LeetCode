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
    bool isCompleteTree(TreeNode* root) {
        if(!root)
            return 1;
        
        bool check = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()){
            auto curr = q.front();
            q.pop();
            if(curr==NULL){
                check = 1;
            }
            else{
                if(check)
                    return 0;
                q.push(curr->left);
                q.push(curr->right);
            }
            
        }
        return 1;        
    }
};