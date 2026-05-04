class MyHashSet {
public:
    vector<list<int>>v;
    int M;
    MyHashSet() {
        v.resize(15000);
        M=15000;
    }
    
    int getIndex(int key){
        return key%M;
    }

    void add(int key) {
        int idx=getIndex(key);
        auto itr=find(v[idx].begin(),v[idx].end(),key);
        if(itr==v[idx].end())
        v[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx=getIndex(key);
        auto itr=find(v[idx].begin(),v[idx].end(),key);
        if(itr!=v[idx].end())
        v[idx].erase(itr);
    }
    
    bool contains(int key) {
        int idx=getIndex(key);
        auto itr=find(v[idx].begin(),v[idx].end(),key);
        return itr!=v[idx].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */