class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int balance=0;
        int deficient=0;
        int start=0;
        for(int i=0;i<gas.size();i++){
             if(balance+gas[i]<cost[i]){
                  deficient+=balance+gas[i]-cost[i];
                  start=i+1;
                  balance=0;
             }
             else{
                balance+=gas[i]-cost[i];
             }
        }
        if(balance+deficient>=0)
        return start;
        return -1;
    }
};