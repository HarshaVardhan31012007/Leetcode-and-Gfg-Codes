class BrowserHistory {
public:
    vector<string>browserPages;
    int rear;
    int current;
    BrowserHistory(string homepage) {
        browserPages.push_back(homepage);
        rear=0;
        current=0;
    }
    
    void visit(string url) {
        int pos=current+1;
        if(current==rear){
            if(pos<browserPages.size()){
                browserPages[pos]=url;
            }
            else{
                browserPages.push_back(url);
            }
        }
        else{
            browserPages[pos]=url;
        }
        rear=pos;
        current=pos;
    }
    
    string back(int steps) {
        current=max(0,current-steps);
        return browserPages[current];
    }
    
    string forward(int steps) {
        current=min(rear,current+steps);
        return browserPages[current];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */