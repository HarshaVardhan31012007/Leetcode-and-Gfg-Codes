class Allocator {
public:
    set<pair<int,int>>freeIntervals;
    unordered_map<int,vector<pair<int,int>>>allocatedIntervals;
    Allocator(int n) {
        freeIntervals.insert({0,n-1});
    }
    
    int allocate(int size, int mID) {
        for(auto it=freeIntervals.begin();it!=freeIntervals.end();it++){
            int l=it->first;
            int r=it->second;
            if((r-l+1)>=size){
                int end=l+size-1;
                allocatedIntervals[mID].push_back({l,end});
                if(end<r){
                    freeIntervals.insert({end+1,r});
                }
                freeIntervals.erase(it);
                return l;
            }
        }
        return -1;
    }
    void insertAndMerge(int l,int r){
        auto it=freeIntervals.upper_bound({l,r});
        if(it!=freeIntervals.begin()){
            auto prev=it;
            prev--;
            if(prev->second+1==l){
                l=prev->first;
                freeIntervals.erase(prev);
            }
        }
        if(it!=freeIntervals.end()){
            if(it->first==r+1){
                r=it->second;
                freeIntervals.erase(it);
            }
        }
        freeIntervals.insert({l,r});
    }
    int freeMemory(int mID) {
        if(!allocatedIntervals.count(mID)) return 0;
        int freed=0;
        for(auto &each:allocatedIntervals[mID]){
            int l=each.first;
            int r=each.second;
            freed+=(r-l+1);
            insertAndMerge(l,r);
        }
        allocatedIntervals.erase(mID);
        return freed;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */