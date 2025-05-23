class Solution {
  public:
    int minCost(vector<int>& arr) {
        if(arr.size()<=1) return 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &a:arr)
        pq.push(a);
        int cost=0;
        while(pq.size()>1){
            auto a=pq.top();
            pq.pop();
            auto b=pq.top();
            pq.pop();
            cost+=a+b;
            pq.push(a+b);
        }
        return cost;
    }
};