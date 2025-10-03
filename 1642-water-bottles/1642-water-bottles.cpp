class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // int ans=0;
        // int empty=0;
        // while(numBottles!=0){
        // ans+=numBottles;
        // int newnumBottles=(empty+numBottles)/numExchange;
        // empty=(empty+numBottles)%numExchange;
        // numBottles=newnumBottles;
        // }
        // return ans;


        // int ans=0;
        // while(numBottles>=numExchange){
        //      ans+=numExchange;
        //      numBottles-=numExchange;
        //      numBottles+=1;
        // }
        // return ans+numBottles;


        // return numBottles+(numBottles-1)/(numExchange-1);

        return numExchange*((numBottles-1)/(numExchange-1))+(numBottles-1)%(numExchange-1)+1;
    }
};