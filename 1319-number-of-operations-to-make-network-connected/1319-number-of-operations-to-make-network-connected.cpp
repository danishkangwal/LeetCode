struct DSU{
private:
    vector<int> parent, siz;
public:
    DSU(int n) {
        siz.resize(n + 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i)
        {
            parent[i] = i;
            siz[i] = 1;
        }
    }

    int findParent(int node) {
        while (node != parent[node])
            node = parent[node] = parent[parent[node]];
        return node;
    }

    bool same(int u, int v) {
        return findParent(u) == findParent(v);
    }

    void merge(int u, int v) {
        int p1 = findParent(u);
        int p2 = findParent(v);
        if (p1 == p2)
            return;
        if (siz[p1] < siz[p2]) {
            parent[p1] = p2;
            siz[p2] += siz[p1];
        }
        else {
            parent[p2] = p1;
            siz[p1] += siz[p2];
        }
    }

    int size(int node) {
        return siz[findParent(node)];
    }

    int number() {
        set<int> s;
        for (int i = 0; i < parent.size()-1; ++i)
        {
            s.insert(findParent(i));
        }
        return s.size();
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1>connections.size()){
            return -1;
        }
        DSU d(n);
        for(auto&i:connections){
            d.merge(i[0],i[1]);
        }
        
        return d.number()-1;
    }
};