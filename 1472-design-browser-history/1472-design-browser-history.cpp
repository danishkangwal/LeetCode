class DoublyNode {
public:
    string val;
    DoublyNode* prev;
    DoublyNode* next;

    DoublyNode(string value) {
        val = value;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory {
    DoublyNode* head;
    DoublyNode* curr;
public:
    BrowserHistory(string homepage) {
        head = new DoublyNode(homepage);
        curr = head;
    }
    
    void visit(string url) {
        if(curr->next == NULL)
            curr->next = new DoublyNode(url);
        else{
            curr->next->val = url;
            curr->next->next = NULL;
        }
        curr->next->prev = curr;
        curr = curr->next;
    }
    
    string back(int steps) {
        while(steps and curr->prev){
            curr = curr->prev;
            steps--;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        while(steps and curr->next){
            curr = curr->next;
            steps--;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */