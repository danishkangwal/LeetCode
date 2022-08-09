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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> rem;
        rem.push(root);
        vector<vector<int>> ans;
        int level = 0; //0 for odd levels and 1 for even levels
        
        while(rem.size()){
            int n = rem.size();
            vector<int> curr(n);
            for(int i = 0;i < n;i++){
                TreeNode *front = rem.front();
                rem.pop();
                if(level){
                    curr[n-i-1] = front->val;
                }else{
                    curr[i] = front->val;
                }
                if(front->left)rem.push(front->left);
                if(front->right)rem.push(front->right);
            }
            ans.push_back(curr);
            level = !level;
        }
        
        return ans;
        
    }
};