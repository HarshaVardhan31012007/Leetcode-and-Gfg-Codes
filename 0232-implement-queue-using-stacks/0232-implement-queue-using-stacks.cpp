class MyQueue {
public:
    // stack<int>s1;
    // stack<int>s2;
    // MyQueue() {
        
    // }
    
    // void push(int x) {
    //     while(!s1.empty()){
    //         s2.push(s1.top());
    //         s1.pop();
    //     }
    //     s1.push(x);
    //     while(!s2.empty()){
    //         s1.push(s2.top());
    //         s2.pop();
    //     }
    // }
    
    // int pop() {
    //      int ans=s1.top();
    //      s1.pop();
    //      return ans;
    // }
    
    // int peek() {
    //     return s1.top();
    // }
    
    // bool empty() {
    //     return s1.empty();
    // }



    stack<int>s1;
    stack<int>s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int ans;
       if(!s2.empty()){
        ans=s2.top();
        s2.pop();
       }
       else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            ans=s2.top();
            s2.pop();
       }
       return ans;
    }
    
    int peek() {
        int ans;
         if(!s2.empty()){
        ans=s2.top();
       }
       else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
             ans=s2.top();
       }
       return ans;
    }
    
    bool empty() {
        return s1.empty()&&s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */