class BrowserHistory {
    vector<string> tab;
    int curr;
    int size;
public:
    BrowserHistory(string homepage) {
        tab.push_back(homepage);
        curr = 0;
        size = 1;
    }
    
    void visit(string url) {
        if(curr == size-1){
            tab.push_back(url);
        }
        else{
            tab.erase(tab.begin()+curr+1,tab.end());
            tab.push_back(url);
        }
        curr++;
        size = tab.size();
    }
    
    string back(int steps) {
        curr = max(0,curr-steps);
        return tab[curr];
    }
    
    string forward(int steps) {
        curr = min(size-1,curr+steps);
        return tab[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */