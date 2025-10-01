class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0;
        int empty=0;
        while(numBottles!=0){
        ans+=numBottles;
        int newnumBottles=(empty+numBottles)/numExchange;
        empty=(empty+numBottles)%numExchange;
        numBottles=newnumBottles;
        }
        return ans;
    }
};