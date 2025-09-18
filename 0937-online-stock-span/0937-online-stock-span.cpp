class StockSpanner {
public:
    // int idx;
    // stack<pair<int,int>>st;
    // StockSpanner() {
    //     idx=-1;
    // }
    
    // int next(int price) {
    //     while(!st.empty()&&st.top().second<=price){
    //         st.pop();
    //     }
    //     int curr=st.empty()?-1:st.top().first;
    //     idx++;
    //     st.push({idx,price});
    //     return idx-curr;
    // }


    stack<pair<int,int>>st;
    StockSpanner() {

    }
    
    int next(int price) {
        int count=1;
        while(!st.empty()&&st.top().second<=price){
            count+=st.top().first;
            st.pop();
        }
        st.push({count,price});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */