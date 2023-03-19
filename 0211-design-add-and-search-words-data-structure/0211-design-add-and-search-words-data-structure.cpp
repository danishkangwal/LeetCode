class TrieNode {
public:
    bool isWord;
    TrieNode* children[26];
    TrieNode() {
        isWord = false;
        memset(children, NULL, sizeof(children));
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char& c : word) {
            if (node -> children[c - 'a']==NULL) {
                node -> children[c - 'a'] = new TrieNode();
            }
            node = node -> children[c - 'a'];
        }
        node -> isWord = true;
    }
    
    
    bool search(TrieNode* node,string word) {
        if(word.size()==0)
            return node->isWord;
        char ch = word[0];
        if(ch!='.'){
            if(!node->children[ch-'a'])
                return 0;
            return search(node->children[ch-'a'],word.substr(1));
        }
        else{
            for(int i = 0;i < 26;i++){
                if(node->children[i] and search(node->children[i],word.substr(1)))
                    return 1;
            }
            return 0;
        }
    }
    
    bool search(string word) {
        return search(root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */