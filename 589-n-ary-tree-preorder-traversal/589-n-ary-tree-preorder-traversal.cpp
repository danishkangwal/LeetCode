/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        std::vector<int> preorder{};
        this->traverse(root, preorder);
        return preorder;
    }
    
    void traverse(const Node* current, std::vector<int>& preorder) {
        if (!current)
            return;
        
        preorder.push_back(current->val);
        for (const Node* child : current->children)
            this->traverse(child, preorder);
    }
};