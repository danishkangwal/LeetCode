class TrieNode{
public:
	char data;
	TrieNode** children;
	bool isTerminal;
	
	TrieNode(char data){
		this->data = data;
		children = new TrieNode*[26];
		for (int i = 0; i < 26; ++i)
		{
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(TrieNode* root,string word){
        if(!word.size()){
            root->isTerminal = true;
            return;
        }
        int index = word[0]-'a';
        TrieNode* child = root->children[index];
        if(child==NULL){
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insert(child,word.substr(1));
    }
    
    void insert(string word) {
        insert(root,word);
    }
    
    bool search(TrieNode* root,string word,bool terminalCheck){
        if(word.size()==0){
            return ((terminalCheck)?root->isTerminal:1);
        }
        int index = word[0]-'a';
        TrieNode* child = root->children[index];
        if(child == NULL){
            return 0;
        }
        return search(child,word.substr(1),terminalCheck);
    }
    
    bool search(string word) {
        return search(root,word,1);
    }
    
    bool startsWith(string prefix) {
        return search(root,prefix,0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */