class MyHashMap {
public:
    vector<list<pair<int,int>>>v;
    int M;
    MyHashMap() {
        v.resize(15000);
        M=15000;
    }

    int getIndex(int key){
        return key%M;
    }
    
    void put(int key, int value) {
        int idx=getIndex(key);
        bool flag=false;
        for(auto it=v[idx].begin();it!=v[idx].end();it++){
            if(it->first==key){
               it->second=value;
               flag=true;
               break;
            }
        }
        if(!flag){
            v[idx].push_back({key,value});
        }
    }
    
    int get(int key) {
        int idx=getIndex(key);
        for(auto it=v[idx].begin();it!=v[idx].end();it++){
            if(it->first==key){
              return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx=getIndex(key);
        for(auto it=v[idx].begin();it!=v[idx].end();it++){
            if(it->first==key){
                v[idx].erase(it);
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */