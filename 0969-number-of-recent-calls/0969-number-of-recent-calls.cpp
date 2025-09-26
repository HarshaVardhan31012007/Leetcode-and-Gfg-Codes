class RecentCounter {
public:
    // stack<int>st;
    // stack<int>st1;
    // RecentCounter() {
        
    // }
    
    // int ping(int t) {
    //     int count=1;
    //     while(!st.empty()&&st.top()>=t-3000){
    //         count++;
    //         st1.push(st.top());
    //         st.pop();
    //     }
    //     while(!st1.empty()){
    //         st.push(st1.top());
    //         st1.pop();
    //     }
    //     st.push(t);
    //     return count;
    // }

   
    queue<int>q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
       while(!q.empty()&&q.front()<t-3000)
       q.pop();
       q.push(t);
       return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */