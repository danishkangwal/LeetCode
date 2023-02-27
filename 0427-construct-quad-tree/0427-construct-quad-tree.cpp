/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    vector<vector<int>> grid;
    Node* construct(vector<vector<int>>& g) {
        grid.resize(g.size(),vector<int>(g.size()));
        for(int i = 0;i < g.size();i++){
            for(int j = 0;j < g.size();j++){
                grid[i][j] = g[i][j];
            }
        }
        return helper(grid.size(),0,0);
    }
private:
    Node* helper(int n,int r,int c){
        bool allSame = true;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(grid[r][c] != grid[r+i][c+j]){
                    allSame = false;
                    i = n;
                    break;
                }
            }
        }
        if(allSame){
            Node* node = new Node(grid[r][c],true);
            return node;
        }
        n = n/2;
        Node* topleft = helper(n,r,c);
        Node* topright = helper(n,r,c+n);
        Node* bottomleft = helper(n,r+n,c);
        Node* bottomright = helper(n,r+n,c+n);
        Node* node = new Node(0,false,topleft,topright,bottomleft,bottomright);
        return node;
    }
};