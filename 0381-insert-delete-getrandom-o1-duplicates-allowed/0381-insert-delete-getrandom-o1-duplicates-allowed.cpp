class RandomizedCollection {
public:
    vector<int>v;
    unordered_map<int,unordered_set<int>>mpp;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool ans=true;
        if(mpp.count(val)) ans=false;
        mpp[val].insert(v.size());
        v.push_back(val);
        return ans;
    }
    
    bool remove(int val) {
        if(!mpp.count(val)) return false;
        int idx=(*(mpp[val].begin()));
        int key=v[idx];
        mpp[key].erase(idx);
        if(mpp[key].empty()) mpp.erase(key);
        if(idx==v.size()-1) v.pop_back();
        else{
            v[idx]=v.back();
            v.pop_back();
            key=v[idx];
            mpp[key].erase(v.size());
            mpp[key].insert(idx);
        }
        return true;
    }
    
    int getRandom() {
        return v[random()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */