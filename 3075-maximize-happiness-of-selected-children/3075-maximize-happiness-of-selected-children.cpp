class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum=0;
        priority_queue<int,vector<int>,greater<>>pq;
        for(int i=0;i<happiness.size();i++){
            if(i<k){
               pq.push(happiness[i]);
               sum+=happiness[i];
            }
            else{
                if(happiness[i]>pq.top()){
                    sum-=pq.top();
                    pq.pop();
                    pq.push(happiness[i]);
                    sum+=happiness[i];
                }
            }
        }
        int turn=k-1;
        while(!pq.empty()){
            sum-=min(turn,pq.top());
            pq.pop();
            turn--;
        }
        return sum;
    }
};