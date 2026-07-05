class Node{
    public:
    int freq,key,value;
    Node* next;
    Node* prev;
    Node(int key,int value){
        this->key=key;
        this->value=value;
        this->freq=1;
        this->next=this->prev=NULL;
    }
};
class List{
    public:
    Node* head;
    Node* tail;
    int size;

    List(){
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        size=0;
    }

    void insertNode(Node* node){
        node->next=head->next;
        head->next->prev=node;
        node->prev=head;
        head->next=node;
        size++;
    }

    void removeNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
        node->next=node->prev=NULL;
        size--;
    }

    Node* removeLRU(){
        Node* node=tail->prev;
        removeNode(node);
        return node;
    }
};
class LFUCache {
public:
    unordered_map<int,Node*>mpp1;
    unordered_map<int,List*>mpp2;
    int maxSize;
    int minfreq;
    LFUCache(int capacity) {
        maxSize=capacity;
        minfreq=INT_MAX;
    }
    void updateFreq(Node* node){
        mpp2[node->freq]->removeNode(node);
        if(mpp2[node->freq]->size==0){
           mpp2.erase(node->freq);
           if(minfreq==node->freq)
           minfreq++;
        }
        node->freq++;
        if(!mpp2.count(node->freq)) mpp2[node->freq]=new List();
        mpp2[node->freq]->insertNode(node);
    }
    int get(int key) {
        if(!mpp1.count(key)) return -1;
        Node* node=mpp1[key];
        updateFreq(node);
        return node->value;
    }

    void put(int key, int value) {
        Node* node;
        if(!mpp1.count(key)){
            if(mpp1.size()==maxSize){
                node=mpp2[minfreq]->removeLRU();
                if(mpp2[node->freq]->size==0){
                    mpp2.erase(node->freq);
                }
                mpp1.erase(node->key);
                delete node;
            }
            node=new Node(key,value);
            minfreq=1;
            if(!mpp2.count(minfreq)) mpp2[minfreq]=new List();
            mpp2[minfreq]->insertNode(node);
            mpp1[key]=node;
        }
        else{
            node=mpp1[key];
            updateFreq(node);
            node->value=value;
        }
    }    
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */