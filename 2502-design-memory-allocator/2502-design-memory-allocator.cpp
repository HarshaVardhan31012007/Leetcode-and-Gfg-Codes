class Allocator {
public:
    vector<int>arr;
    int N;
    Allocator(int n) {
        arr.resize(n);
        N=n;
    }
    
    int allocate(int size, int mID) {
        int start=0;int end=-1;
        int len=0;
        for(int i=0;i<N;i++){
            if(arr[i]==0){
                len++;
                if(len==size){
                    end=i;
                    break;
                }
            }
            else{
                start=i+1;
                len=0;
            }
        }
        if(end==-1) return -1;
        for(int i=start;i<=end;i++) arr[i]=mID;
        return start;
    }
    
    int freeMemory(int mID) {
        int ans=0;
        for(int i=0;i<N;i++){
            if(arr[i]==mID){
                arr[i]=0;
                ans++;
            }
        }
        return ans;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */