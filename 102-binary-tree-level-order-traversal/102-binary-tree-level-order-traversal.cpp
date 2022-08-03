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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {}; 
        
        // vector<vector <int>> ans;
        vector<vector<int>> ans(2001);

        int index = 0;
        queue<TreeNode *> remaining;
        remaining.push(root);
        remaining.push(NULL);
        while(remaining.size()){
            TreeNode *front = remaining.front();
            remaining.pop();
            if(front){
                ans[index].push_back(front->val);
                if(front->left) remaining.push(front->left);
                if(front->right) remaining.push(front->right);
            
            }else{
                index++;
                if(!remaining.size()) break;
                remaining.push(NULL);
            }
            
        }
        ans.erase(ans.begin()+index,ans.end());
        
        return ans;
    }
};