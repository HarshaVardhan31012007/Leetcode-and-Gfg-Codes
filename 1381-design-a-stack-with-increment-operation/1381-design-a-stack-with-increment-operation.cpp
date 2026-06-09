class CustomStack {
public:
    stack<int>st1;
    stack<int>st2;
    int inc;
    int maxi;
    CustomStack(int maxSize) {
        inc=0;
        maxi=maxSize;
    }
    
    void push(int x) {
        if(st1.size()<maxi)
        st1.push(x-inc);
    }
    
    int pop() {
        if(st1.empty()) return -1;
        int top=st1.top();
        st1.pop();
        return top+inc;
    }
    
    void increment(int k, int val) {
        inc+=val;
        if(st1.size()<=k) return;
        int size=(st1.size()-k);
        for(int i=0;i<size;i++){
            st2.push(st1.top()-val);st1.pop();
        }
        for(int i=0;i<size;i++){
            st1.push(st2.top());st2.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */