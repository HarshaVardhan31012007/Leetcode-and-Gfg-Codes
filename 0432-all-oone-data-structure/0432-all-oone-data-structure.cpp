// class AllOne {
// public:
//     map<string,int>mpp;
//     map<int,unordered_set<string>>freq;
//     AllOne() {
       
//     }
    
//     void inc(string key) {
//         if(mpp.count(key)){
//             int f=mpp[key];
//             freq[f].erase(key);
//             if(freq[f].empty()) freq.erase(f);
//         }
//         mpp[key]++;
//         freq[mpp[key]].insert(key);
//     }
    
//     void dec(string key) {
//         int f=mpp[key];
//         freq[f].erase(key);
//         if(freq[f].empty()) freq.erase(f);
//         mpp[key]--;
//         if(mpp[key]==0){
//             mpp.erase(key);
//             return;
//         }
//         freq[mpp[key]].insert(key);
//     }
    
//     string getMaxKey() {
//         if(freq.empty()) return "";
//         auto it=freq.end();
//         it--;
//         return *(it->second.begin());
//     }
      
//     string getMinKey() {
//         if(freq.empty()) return "";
//         auto it=freq.begin();
//         return *(it->second.begin());
//     }
// };

// /**
//  * Your AllOne object will be instantiated and called as such:
//  * AllOne* obj = new AllOne();
//  * obj->inc(key);
//  * obj->dec(key);
//  * string param_3 = obj->getMaxKey();
//  * string param_4 = obj->getMinKey();
//  */



class Node{
    public:
    int freq;
    unordered_set<string>st;
    Node* next;
    Node* prev;
    Node(int f){
        this->freq=f;
        this->next=this->prev=NULL;
    }
};
class AllOne {
public:
    Node *head,*tail;
    unordered_map<string,Node*>mpp;
    AllOne() {
       head=new Node(0);
       tail=new Node(0);
       head->next=tail;
       tail->prev=head;
    }
    Node* insertAfter(Node* node,int f){
        Node* newNode=new Node(f);
        newNode->next=node->next;
        node->next->prev=newNode;
        node->next=newNode;
        newNode->prev=node;
        return newNode;
    }
    void deleteNode(Node* node){
        Node* prevNode=node->prev;
        Node* nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
        delete node;
    }
    void inc(string key) {
        if(!mpp.count(key)){
           Node* node;
           if(head->next->freq==1){
              node=head->next;
           }
           else{
              node=insertAfter(head,1); 
           }
           node->st.insert(key);
           mpp[key]=node;
           return;
        }
        Node* node=mpp[key];
        node->st.erase(key);
        if(node->next->freq==node->freq+1){
            node->next->st.insert(key);
            mpp[key]=node->next;
        }
        else{
            Node* newNode=insertAfter(node,node->freq+1);
            newNode->st.insert(key);
            mpp[key]=newNode;
        }
        if(node->st.empty()){
            deleteNode(node);
        }
    }
    
    void dec(string key) {
        Node* node=mpp[key];
        node->st.erase(key);
        if(node->freq==1){
           mpp.erase(key);
        }
        else{
            if(node->prev->freq+1==node->freq){
                node->prev->st.insert(key);
                mpp[key]=node->prev;
            }
            else{
                Node* newNode=insertAfter(node->prev,node->freq-1);
                newNode->st.insert(key);
                mpp[key]=newNode;
            }
        }
        if(node->st.empty()){
            deleteNode(node);
        }
    }
    
    string getMaxKey() {
        if(tail->prev->freq==0) return "";
        return *(tail->prev->st.begin());
    }
      
    string getMinKey() {
        if(head->next->freq==0) return "";
        return *(head->next->st.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */