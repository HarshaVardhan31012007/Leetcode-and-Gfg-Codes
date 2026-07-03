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
        // auto it=upper_bound(mpp[key].begin(),mpp[key].end(),make_pair(timestamp,"{"));
        // if(it==mpp[key].begin()) return "";
        // it--;
        // return it->second;
        vector<pair<int,string>>&arr=mpp[key];
        int s=0;
        int e=(int)arr.size()-1;
        string ans="";
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid].first<=timestamp){
                ans=arr[mid].second;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */