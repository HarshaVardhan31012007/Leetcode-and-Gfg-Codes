class LFUCache {
public:
    // class Node{
    //     public:
    //     int key,val,freq;
    //     Node* next;
    //     Node* prev;
    //     Node* lrecent;
    //     Node(int key,int val){
    //         this->key=key;
    //         this->val=val;
    //         this->prev=this->next=NULL;
    //         this->freq=1;
    //         this->lrecent=NULL;
    //     }
    // };
    // Node* head=new Node(-1,-1);
    // Node* tail=new Node(-1,-1);
    // unordered_map<int,Node*>mpp;
    // int limit;
    // LFUCache(int capacity) {
    //     limit=capacity;
    //     head->next=tail;
    //     tail->prev=head;
    // }
    
    // int get(int key) {
        
    // }
    // void removeLinks(Node* node){
    //     node->prev->next=node->next;
    //     node->next->prev=node->prev;
    //     node->next=node->prev=NULL;
    // }
    // void addNode(Node* node){
    //      node->next=head->next;
    //      head->next=node;
    //      node->prev=head;
    //      node->next->prev=node;
    // }
    // void put(int key, int value) {
    //     auto it=mpp.find(key);
    //     if(it!=mpp.end()){
    //         Node* curr=it->second;
    //         curr->val=value;
    //         curr->freq+=1;
    //         if(curr->freq>head->freq){
    //              removeLinks(curr);
    //              addNode(curr);
    //              curr->lrecent=curr;
    //         }
    //         else if(curr->freq==head->freq){
    //              removeLinks(curr);
    //              addNode(curr);
    //              curr->lrecent=head->lrecent;
    //         }
    //     }
    //     else{
    //         if(mpp.size()==limit){
               
    //         }
    //         Node* newNode=new Node(key,value);
    //         addNode(newNode);
    //         newNode->lrecent=newNode;
    //         mpp[key]=newNode;
    //     }
    // }




    unordered_map<int,list<vector<int>>::iterator>mpp;
    map<int,list<vector<int>>>freqMap;
    int limit;
    LFUCache(int capacity) {
        limit=capacity;
    }
    void updateList(int key){
        auto& vec=*(mpp[key]);
        int f=vec[2];
        int value=vec[1];
        freqMap[f].erase(mpp[key]);
        if(freqMap[f].empty()){
           freqMap.erase(f);
        }
        f++;
        freqMap[f].push_front({key,value,f});
        mpp.erase(key);
        mpp[key]=freqMap[f].begin();
    }
    int get(int key) {
        auto it=mpp.find(key);
        if(it==mpp.end())
        return -1;
        auto vec=*(it->second);
        updateList(key);
        return vec[1];
    }

    void put(int key, int value) {
          auto it=mpp.find(key);
          if(it!=mpp.end()){
               auto &vec=*(it->second);
               vec[1]=value;
               updateList(key);
          }
          else{
              if(mpp.size()==limit){
                   auto &rem_list=freqMap.begin()->second;
                   auto vec=rem_list.back();
                   int f=vec[2];
                   mpp.erase(vec[0]);
                   rem_list.pop_back();
                   if(rem_list.empty())
                   freqMap.erase(f);
                   freqMap[1].push_front({key,value,1});
                   mpp[key]=freqMap[1].begin();
              }
              else{
                freqMap[1].push_front({key,value,1});
                mpp[key]=freqMap[1].begin();
              }
          }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */