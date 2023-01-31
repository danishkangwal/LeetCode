class Trie {
private:
    Trie* child[26];
    bool isTerminal;
public:
    Trie() {
        isTerminal = false;
        for(int i = 0;i < 26;i++){
            child[i] = NULL;
        }
    }
    
    void insert(string word) {
        Trie* temp = this;
        for(auto&i:word){
            int index = i-'a';
            Trie* child = temp->child[index];
            if(child == NULL){
                child = new Trie();
                temp->child[index]=child;
            }
            temp = child;
        }
        temp->isTerminal = true;
    }
    
    bool search(string word) {
        Trie* temp = this;
        for(auto&i:word){
            int index = i-'a';
            Trie* child = temp->child[index];
            if(child == NULL){
                return 0;
            }
            temp = child;
        }
        return temp->isTerminal;
    }
    
    bool startsWith(string prefix) {
        Trie* temp = this;
        for(auto&i:prefix){
            int index = i-'a';
            Trie*child = temp->child[index];
            if(child==NULL){
                return 0;
            }
            temp = child;
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