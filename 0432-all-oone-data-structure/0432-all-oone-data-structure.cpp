class AllOne {
public:
    map<string,int>mpp;
    map<int,unordered_set<string>>freq;
    AllOne() {
       
    }
    
    void inc(string key) {
        if(mpp.count(key)){
            int f=mpp[key];
            freq[f].erase(key);
            if(freq[f].empty()) freq.erase(f);
        }
        mpp[key]++;
        freq[mpp[key]].insert(key);
    }
    
    void dec(string key) {
        int f=mpp[key];
        freq[f].erase(key);
        if(freq[f].empty()) freq.erase(f);
        mpp[key]--;
        if(mpp[key]==0){
            mpp.erase(key);
            return;
        }
        freq[mpp[key]].insert(key);
    }
    
    string getMaxKey() {
        if(freq.empty()) return "";
        auto it=freq.end();
        it--;
        return *(it->second.begin());
    }
      
    string getMinKey() {
        if(freq.empty()) return "";
        auto it=freq.begin();
        return *(it->second.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */