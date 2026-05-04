class MyHashSet {
public:
    vector<bool>vec;
    MyHashSet() {
        vec.resize(1000001,0);
    }
    
    void add(int key) {
        vec[key]=1;
    }
    
    void remove(int key) {
        vec[key]=0;
    }
    
    bool contains(int key) {
        return vec[key]==1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */