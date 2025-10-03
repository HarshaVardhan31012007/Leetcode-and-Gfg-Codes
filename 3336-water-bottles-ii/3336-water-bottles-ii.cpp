class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        // int ans=0;
        // int empty=0;
        // while(numBottles!=0||empty>=numExchange){
        //     if(empty>=numExchange){
        //         empty-=numExchange;
        //         numBottles+=1;
        //         numExchange+=1;
        //     }
        //     else{
        //        empty+=numBottles;
        //        ans+=numBottles;
        //        numBottles=0;
        //     }
        // }
        // return ans;


        // int ans=0;
        // while(numBottles>=numExchange){
        //     ans+=numExchange;
        //     //numBottles-=numExchange-1;
        //     numBottles=numBottles-numExchange+1;
        //     numExchange+=1;
        // }
        // return ans+numBottles;


        // int ans=0;
        // while(numBottles>=numExchange){
        //     ans+=numExchange;
        //     //numBottles-=numExchange-1;
        //     numBottles=numBottles-numExchange+1;
        //     numExchange+=1;
        // }
        // return ans+numBottles;


        int ans=numBottles;
        int empty=numBottles;
        while(empty>=numExchange){
            ans++;
            empty-=numExchange-1;
            numExchange+=1;
        }
        return ans;
    }
};