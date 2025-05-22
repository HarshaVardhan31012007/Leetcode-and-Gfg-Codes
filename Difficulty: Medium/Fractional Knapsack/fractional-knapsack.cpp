// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int w) {
        priority_queue<pair<double,pair<int,int>>>pq;
        for(int i=0;i<val.size();i++){
        pq.push({val[i]*1.0/wt[i],{val[i],wt[i]}});
        }
        double ans=0;
        double capacity=w;
        while(!pq.empty()){
            double ratio=pq.top().first;
            int value=pq.top().second.first;
            int weight=pq.top().second.second;
            pq.pop();
            if(capacity>weight){
                ans+=value;
                capacity-=weight;
            }
            else{
                double a=ratio*capacity;
                ans+=a;
                break;
            }
        }
        return ans;
    }
};
