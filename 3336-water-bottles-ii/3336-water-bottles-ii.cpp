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

        //simulatiosn in terms of full bottles(in numBottles variable )
        // int ans=0;
        // while(numBottles>=numExchange){
        //     ans+=numExchange;
        //     //numBottles-=numExchange-1;
        //     numBottles=numBottles-numExchange+1;
        //     numExchange+=1;
        // }
        // return ans+numBottles;

        //simulation interms of empty bottles

        // int ans=numBottles;
        // int empty=numBottles;
        // while(empty>=numExchange){
        //     ans++;
        //     empty-=numExchange-1;
        //     numExchange+=1;
        // }
        // return ans;


        // return numBottles+((-2*numExchange+3)+sqrt(4*numExchange*numExchange-12*numExchange+8*numBottles+1))/2.0;

         int a=1;
         int b=2*numExchange-3;
         double delta=4*numExchange*numExchange-12*numExchange+8*numBottles+1.0;
         return numBottles+(-b+sqrt(delta))/2.0;
    }
};