class MyStack {
public:
// queue<int>q;
queue<int>q1;
queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) {
    //    q.push(x);
    //    for(int i=0;i<q.size()-1;i++){
    //     int front=q.front();
    //     q.pop();
    //     q.push(front);
    //    } 

    q1.push(x);
    while(!q2.empty()){
        int e=q2.front();
        q2.pop();
        q1.push(e);
    }
    while(!q1.empty()){
         int e=q1.front();
        q1.pop();
        q2.push(e);
    }
    }
    
    int pop() {
        // int top=q.front();
        // q.pop();
        // return top;

        int top=q2.front();
        q2.pop();
        return top;
    }
    
    int top() {
    //return q.front();

    return q2.front();
    }
    
    bool empty() {
    //    return q.empty(); 

    return q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */