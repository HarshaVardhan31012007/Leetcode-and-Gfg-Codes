class MinStack {
public:
    // vector<pair<int,int>>v;
    // MinStack() {
        
    // }
    
    // void push(int val) {
    //     if(v.empty())
    //     v.push_back(make_pair(val,val));
    //     else
    //     v.push_back(make_pair(val,min(val,v.back().second)));
    // }
    
    // void pop() {
    //     v.pop_back();
    // }
    
    // int top() {
    //     return v.back().first;
    // }
    
    // int getMin() {
    //     return v.back().second;
    // }




    stack<int>s;
    stack<int>s1;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
        s.push(val);
        s1.push(val);
        }
        else{
            s.push(val);
            s1.push(min(s1.top(),val));
        }
    }
    
    void pop() {
        s.pop();
        s1.pop();
    }
    
    int top() {
        return s.top();
    }
    int getMin() {
         return s1.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */