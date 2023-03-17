class Trie {
private:
    bool isTerminal;
    Trie* child[26];
public:
    Trie() {
        isTerminal = false;
        for(int i = 0;i < 26;i++){
            child[i] = NULL;
        }
    }
    
    void insert(Trie* curr,string word){
        if(word.size()==0){
            curr->isTerminal = true;
            return;
        }
        int idx = word[0]-'a';
        if(curr->child[idx]==NULL)
            curr->child[idx] = new Trie();
        insert(curr->child[idx],word.substr(1));
    }
    
    void insert(string word) {
        insert(this,word);
    }
    
    bool search(Trie* curr,string word,int check){
        if(word.size()==0){
            return check?curr->isTerminal:1;
        }
        int idx = word[0]-'a';
        if(curr->child[idx]==NULL)
            return 0;
        return search(curr->child[idx],word.substr(1),check);
    }
    
    bool search(string word) {
        return search(this,word,1);
    }
    
    bool startsWith(string prefix) {
        return search(this,prefix,0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */