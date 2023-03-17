class TrieNode{
public:    
    bool isTerminal;
    TrieNode* child[26]; 

    TrieNode(){
        isTerminal = false;
        for(int i = 0;i < 26;i++)
            child[i] = NULL;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(auto& ch :word){
            int idx = ch -'a';
            if(temp->child[idx]==NULL)
                temp->child[idx] = new TrieNode();
            temp = temp->child[idx];
        }
        temp->isTerminal = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(auto& ch :word){
            int idx = ch -'a';
            if(temp->child[idx]==NULL)
                return 0;
            temp = temp->child[idx];
        }
        return temp->isTerminal;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(auto& ch :prefix){
            int idx = ch-'a';
            if(temp->child[idx]==NULL)
                return 0;
            temp = temp->child[idx];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */