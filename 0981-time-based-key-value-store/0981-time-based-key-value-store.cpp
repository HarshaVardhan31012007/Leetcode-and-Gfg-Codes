class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(!mpp.count(key)) return "";
        auto it=upper_bound(mpp[key].begin(),mpp[key].end(),make_pair(timestamp,"{"));
        if(it==mpp[key].begin()) return "";
        it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */