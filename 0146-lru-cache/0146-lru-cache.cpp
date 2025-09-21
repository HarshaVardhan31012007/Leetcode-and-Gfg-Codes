class LRUCache {
public:
    // unordered_map<int,int>mpp;
    // vector<int>v;
    // int size;
    // int count=0;
    // int time=0;
    // LRUCache(int capacity) {
    //      size=capacity;
    // }
    // int get(int key) {
    //     if(mpp.find(key)==mpp.end())
    //     return -1;
    //     auto it=find(v.begin(),v.end(),key);
    //     v.erase(it);
    //     v.push_back(key);
    //     return mpp[key];
    // }
    
    // void put(int key, int value) {
    //     if(mpp.find(key)!=mpp.end()){
    //           auto it=find(v.begin(),v.end(),key);
    //           v.erase(it);
    //           mpp[key]=value;
    //     }
    //     else{
    //         if(count<size){
    //         mpp[key]=value;
    //         count++;
    //         }
    //         else{
    //             mpp.erase(v[0]);
    //             v.erase(v.begin());
    //             mpp[key]=value;
    //         }
    //     }
    //     v.push_back(key);
    // }



    class Node{
        public:
        int key,val;
        Node* prev;
        Node* next;
        Node(int key,int val){
            this->key=key;
            this->val=val;
            this->next=this->prev=NULL;
        }
    };
    unordered_map<int,Node*>mpp;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int size;
    LRUCache(int capacity) {
         size=capacity;
         head->next=tail;
         tail->prev=head;
    }
    int get(int key) {
        auto it=mpp.find(key);
        if(it==mpp.end())
        return -1;
        Node* ansNode=it->second;
        deleteNode(ansNode);
        addNode(ansNode);
        return ansNode->val;
    }
    void addNode(Node* newNode){
         newNode->next=head->next;
         head->next=newNode;
         newNode->prev=head;
         newNode->next->prev=newNode;
    }
    void deleteNode(Node* temp){
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        temp->next=NULL;
        temp->prev=NULL;
    }
    void put(int key, int value) {
        auto it=mpp.find(key);
        if(it!=mpp.end()){
              Node* curr=it->second;
              curr->val=value;
              deleteNode(curr);
              addNode(curr);
        }
        else{
            if(mpp.size()<size){
            Node* newNode=new Node(key,value);
            addNode(newNode);
            mpp[key]=newNode;
            }
            else{
                mpp.erase(tail->prev->key);
                Node* temp=tail->prev;
                deleteNode(temp);
                delete temp;
                Node* newNode=new Node(key,value);
                addNode(newNode);
                mpp[key]=newNode;
            }
        }
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */