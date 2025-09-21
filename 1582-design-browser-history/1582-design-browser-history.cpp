class BrowserHistory {
public:
    stack<string>bstack,fwstack;
    BrowserHistory(string homepage) {
        bstack.push(homepage);
    }
    
    void visit(string url) {
        //no s.clear() in stack
        while(!fwstack.empty()){
            fwstack.pop();
        }
        bstack.push(url);
    }
    
    string back(int steps) {
        while(bstack.size()>1){
            if(steps>0){
            fwstack.push(bstack.top());
            bstack.pop();
            steps--;
            }
            else
            break;
        }
        return bstack.top();
    }
    
    string forward(int steps) {
        while(!fwstack.empty()){
            if(steps>0){
                bstack.push(fwstack.top());
                fwstack.pop();
                steps--;
            }
            else
            break;
        }
        return bstack.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */