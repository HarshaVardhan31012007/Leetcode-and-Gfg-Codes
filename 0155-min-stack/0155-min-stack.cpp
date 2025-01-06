class MinStack {
public:
   // vector<pair<int,int>>v;
   //method 2
   stack<long long int>s;
   long long int mini=INT_MAX;
    MinStack() {
      
    }
    
    void push(long long int val) {
        // if(v.empty()){
        //     v.push_back({val,val});
        // }
        // else{
        //     int minAns=val;
        //     if(minAns>v.back().second)
        //     minAns=v.back().second;
        //     v.push_back({val,minAns});
        //     // v.push_back({val,v.back().second<val?v.back().second:val});
        // }
        //method 2
        if(s.empty()){
            s.push(val);
            mini=val;
        }
        else{
            if(val<mini){
                s.push(2*val-mini);
                mini=val;
            }
            else{
                s.push(val);
            }
        }
    }
    
    void pop() {
    //    return v.pop_back();
    //method 2
    if(s.empty())
    return;
    long long int curr=s.top();
    s.pop();
    // if(curr>mini){
    //     //mini will be same no chnage
    //     //we are returning actual pop value which is curr only
    // }
    // else{
    //     int beforepopmin=mini;
    //     int val=2*mini-curr;
    //     mini=val;//mini after pop
    //     //actual pop value is  beforepopmin
    // }

    if(curr<mini){
        //   int beforepopmin=mini;
        // int v=2*mini-curr;
        // mini=v;//mini after pop
        // //actual pop value is  beforepopmin
        mini=2*mini-curr;
    }
    }

    long long int top() {
    //    return v.back().first;
    //method 2
    if(s.empty())
    return -1;
    long long int curr=s.top();
    if(curr<mini){
       return mini;
    }
    else{
       return curr;
    }
    }
    long long int getMin() {
        // return v.back().second;
        //method 2
        if(s.empty())
        return -1;
        return mini;
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