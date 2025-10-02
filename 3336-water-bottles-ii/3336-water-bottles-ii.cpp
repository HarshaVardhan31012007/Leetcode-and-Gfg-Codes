class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=0;
        int empty=0;
        while(numBottles!=0||empty>=numExchange){
            if(empty>=numExchange){
                empty-=numExchange;
                numBottles+=1;
                numExchange+=1;
            }
            else{
               empty+=numBottles;
               ans+=numBottles;
               numBottles=0;
            }
        }
        return ans;
    }
};