class FreqStack {
public:

    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>mpp;
    int maxfreq;

    FreqStack() {
        maxfreq=INT_MIN; 
    }  

    void push(int val) {
        freq[val]++;
        maxfreq=max(maxfreq,freq[val]);
        mpp[freq[val]].push(val);
    }
    
    int pop() {
        int ans=mpp[maxfreq].top();
        mpp[maxfreq].pop();
        freq[ans]--;
        if(mpp[maxfreq].empty()){
           mpp.erase(maxfreq);
           maxfreq--;
        }
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */