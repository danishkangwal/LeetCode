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
};

class Solution{
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU d(n);
        int minScore = INT_MAX;
        for(auto&i:roads){
            d.merge(i[0],i[1]);
        }
        int parent = d.findParent(1);
        for(auto&i :roads){
            if(d.findParent(i[0]) == parent){
                minScore = min(minScore,i[2]);
            }
        }

        return minScore;
    }
};