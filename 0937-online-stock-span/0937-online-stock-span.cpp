class StockSpanner {
public:
    // vector<int>ans;
    // StockSpanner() {
        
    // }
    
    // int next(int price) {
    //     ans.push_back(price);
    //     int count=1;
    //     int t=ans[ans.size()-1];
    //     for(int i=ans.size()-2;i>=0;i--){
    //         if(ans[i]<=t)
    //         count++;
    //         else
    //         break;
    //     }
    //     return count;
    // }



    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
       int span=1;
       while(!st.empty()&&st.top().first<=price){
        span+=st.top().second;
        st.pop();
       }
       st.push({price,span});
       return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */