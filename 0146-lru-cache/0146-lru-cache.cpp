class LRUCache {
public:
    class List{
        public:
        int data;
        int key;
        List* prev;
        List* next;
        List(int val,int k){
            this->data=val;
            this->key=k;
            this->prev=NULL;
            this->next=NULL;
        }
    };
    unordered_map<int,List*>keyToNodeLink;
    List* head,*tail;
    int size;
    int maxSize;
    void insert(List* node){
        if(!head){
            head=node;
            tail=node;
        }
        else{
            tail->next=node;
            node->prev=tail;
            tail=node;
        }
    }
    LRUCache(int capacity) {
        head=NULL;
        tail=NULL;
        size=0;
        maxSize=capacity;
    }
    
    int get(int key) {
        if(keyToNodeLink.count(key)){
           int value=keyToNodeLink[key]->data;
           List* node=keyToNodeLink[key];
           if(size==1){
              head=NULL;
              tail=NULL;
           }
           else{
            if(node->prev)
            node->prev->next=node->next;
            else
            head=head->next;
            if(node->next)
            node->next->prev=node->prev;
            else
            tail=tail->prev;
            node->prev=NULL;
            node->next=NULL;
           }
           insert(node);
           return value;
        }
        else
        return -1;
    }
    
    void put(int key, int value) {
        if(!keyToNodeLink.count(key)){
            List *newNode=new List(value,key);
            if(size<maxSize){
                keyToNodeLink[key]=newNode;
                insert(newNode);
                size++;
            }
            else{
                List* node=head;
                if(size==1){
                    head=NULL;
                    tail=NULL;
                }
                else{
                    if(node->prev)
                    node->prev->next=node->next;
                    else
                    head=head->next;
                    if(node->next)
                    node->next->prev=node->prev;
                    else
                    tail=tail->prev;
                    node->prev=NULL;
                    node->next=NULL;
                    node->data=value;
                }
                keyToNodeLink.erase(node->key);
                delete node;
                keyToNodeLink[key]=newNode;
                insert(newNode);
            }
        }
        else{
           List* node=keyToNodeLink[key];
           node->data=value;
           if(size==1){
              head=NULL;
              tail=NULL;
           }
           else{
            if(node->prev)
            node->prev->next=node->next;
            else
            head=head->next;
            if(node->next)
            node->next->prev=node->prev;
            else
            tail=tail->prev;
            node->prev=NULL;
            node->next=NULL;
           }
           insert(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */