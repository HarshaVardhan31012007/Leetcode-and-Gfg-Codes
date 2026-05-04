class RandomizedSet {
public:
    unordered_map<int,int>mpp;
    vector<int>v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mpp.count(val)) return false;
        mpp[val]=v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!mpp.count(val)) return false;
        int idx=mpp[val];
        if(idx==v.size()-1){
            v.pop_back();
            mpp.erase(val);
        }
        else{
            mpp.erase(val);
            v[idx]=v.back();
            v.pop_back();
            mpp[v[idx]]=idx;
        }
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */