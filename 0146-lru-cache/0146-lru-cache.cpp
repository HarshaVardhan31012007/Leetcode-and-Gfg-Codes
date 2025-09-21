class LRUCache {
public:
    unordered_map<int,int>mpp;
    vector<int>v;
    int size;
    int count=0;
    int time=0;
    LRUCache(int capacity) {
         size=capacity;
    }
    int get(int key) {
        if(mpp.find(key)==mpp.end())
        return -1;
        auto it=find(v.begin(),v.end(),key);
        v.erase(it);
        v.push_back(key);
        return mpp[key];
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
              auto it=find(v.begin(),v.end(),key);
              v.erase(it);
              mpp[key]=value;
        }
        else{
            if(count<size){
            mpp[key]=value;
            count++;
            }
            else{
                mpp.erase(v[0]);
                v.erase(v.begin());
                mpp[key]=value;
            }
        }
        v.push_back(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */