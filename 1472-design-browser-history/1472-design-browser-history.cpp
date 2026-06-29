// class BrowserHistory {
// public:
//     vector<string>browserPages;
//     int rear;
//     int current;
//     BrowserHistory(string homepage) {
//         browserPages.push_back(homepage);
//         rear=0;
//         current=0;
//     }
    
//     void visit(string url) {
//         int pos=current+1;
//         if(current==rear){
//             if(pos<browserPages.size()){
//                 browserPages[pos]=url;
//             }
//             else{
//                 browserPages.push_back(url);
//             }
//         }
//         else{
//             browserPages[pos]=url;
//         }
//         rear=pos;
//         current=pos;
//     }
    
//     string back(int steps) {
//         current=max(0,current-steps);
//         return browserPages[current];
//     }
    
//     string forward(int steps) {
//         current=min(rear,current+steps);
//         return browserPages[current];
//     }
// };

// /**
//  * Your BrowserHistory object will be instantiated and called as such:
//  * BrowserHistory* obj = new BrowserHistory(homepage);
//  * obj->visit(url);
//  * string param_2 = obj->back(steps);
//  * string param_3 = obj->forward(steps);
//  */



// class BrowserHistory {
// public:
//     vector<string>browserPages;
//     int current;
//     BrowserHistory(string homepage) {
//         browserPages.push_back(homepage);
//         current=0;
//     }
    
//     void visit(string url) {
//         int size=browserPages.size();
//         int noOfDeletes=(size-(current+1));
//         while(noOfDeletes--){
//             browserPages.pop_back();
//         }
//         browserPages.push_back(url);
//         current=current+1;
//     }
    
//     string back(int steps) {
//         current=max(0,current-steps);
//         return browserPages[current];
//     }
    
//     string forward(int steps) {
//         int size=browserPages.size();
//         current=min(size-1,current+steps);
//         return browserPages[current];
//     }
// };

// /**
//  * Your BrowserHistory object will be instantiated and called as such:
//  * BrowserHistory* obj = new BrowserHistory(homepage);
//  * obj->visit(url);
//  * string param_2 = obj->back(steps);
//  * string param_3 = obj->forward(steps);
//  */


class Node{
    public:
    string data;
    Node* next;
    Node* prev;
    Node(string temp){
        this->data=temp;
        this->next=this->prev=NULL;
    }
};
class BrowserHistory {
public:
    Node* head;
    Node* current;
    BrowserHistory(string homepage) {
        head=new Node(homepage);
        current=head;
    }
    
    void visit(string url) {
        Node* temp=current->next;
        while(temp){
            Node* node=temp;
            temp=temp->next;
            delete node;
        }
        current->next=new Node(url);
        current->next->prev=current;
        current=current->next;
    }
    
    string back(int steps) {
        while(steps--&&current->prev){
            current=current->prev;
        }
        return current->data;
    }
    
    string forward(int steps) {
        while(steps--&&current->next){
            current=current->next;
        }
        return current->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */