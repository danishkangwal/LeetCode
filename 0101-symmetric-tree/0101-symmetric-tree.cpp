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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return 1;
        
        stack<TreeNode*> st;
        st.push(root->left);
        st.push(root->right);
        while(st.size()){
            TreeNode* t1 = st.top();st.pop();
            TreeNode* t2 = st.top();st.pop();
            if(!t1 and !t2)
                continue;
            if(!t1 || !t2 || t1->val!=t2->val)
                return 0;
            st.push(t1->right);st.push(t2->left);
            st.push(t1->left);st.push(t2->right);
        }
        return 1;
    }
};