class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
       long long both=0;
        long long cost=0;
        if(need1>need2){
            long long diff=need1-need2;
            if(cost1<costBoth){
                 cost+=cost1*diff*1LL;
            }
            else{
                 cost+=costBoth*diff*1LL;
            }
            need1-=diff;
        }
        else if(need2>need1){
            long long diff=need2-need1;
            if(cost2<costBoth){
                cost+=cost2*diff*1LL;
            }
            else{
                cost+=costBoth*diff*1LL;
            }
            need2-=diff;
        }
        long long curr=min(cost1+cost2,costBoth);
        cost+=curr*need1*1LL;
        return cost;
    }
};