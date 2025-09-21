class BrowserHistory {
public:
    // stack<string>bstack,fwstack;
    // BrowserHistory(string homepage) {
    //     bstack.push(homepage);
    // }
    
    // void visit(string url) {
    //     //no s.clear() in stack
    //     while(!fwstack.empty()){
    //         fwstack.pop();
    //     }
    //     bstack.push(url);
    // }
    
    // string back(int steps) {
    //     while(bstack.size()>1){
    //         if(steps>0){
    //         fwstack.push(bstack.top());
    //         bstack.pop();
    //         steps--;
    //         }
    //         else
    //         break;
    //     }
    //     return bstack.top();
    // }
    
    // string forward(int steps) {
    //     while(!fwstack.empty()){
    //         if(steps>0){
    //             bstack.push(fwstack.top());
    //             fwstack.pop();
    //             steps--;
    //         }
    //         else
    //         break;
    //     }
    //     return bstack.top();
    // }


    // vector<string>v;
    // int i;
    // BrowserHistory(string homepage) {
    //    i=0;
    //    v.push_back(homepage);
    // }
    
    // void visit(string url) {
    //     if(i+1<v.size())
    //     v.erase(v.begin()+i+1,v.end());
    //     v.push_back(url);
    //     i++;
    // }
    
    // string back(int steps) {
    //    i=i-steps;
    //    if(i<0)
    //    i=0;
    //    return v[i];
    // }
    
    // string forward(int steps) {
    //    i=i+steps;
    //    if(i>=v.size())
    //    i=v.size()-1;
    //    return v[i];
    // }


    class Node{
        public:
        string data;
        Node* next;
        Node* prev;
        Node(string val){
            this->data=val;
            this->next=NULL;
            this->prev=NULL;
        }
    };
    Node* head=NULL;
    Node* temp=head;
    BrowserHistory(string homepage) {
      head=new Node(homepage);
      temp=head;
    }
    
    void visit(string url) {
        Node* temp2=temp;
        Node* temp1=temp->next;
        temp->next=new Node(url);
        temp=temp->next;
        temp->prev=temp2;
        while(temp1){
            Node* t=temp1->next;
            temp1->next=NULL;
            temp1->prev=NULL;
            delete temp1;
            temp1=t;
        }
    }
    
    string back(int steps) {
        while(steps--&&temp->prev){
            temp=temp->prev;
        }
        return temp->data;
    }
    
    string forward(int steps) {
        while(steps--&&temp->next){
            temp=temp->next;
        }
        return temp->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */