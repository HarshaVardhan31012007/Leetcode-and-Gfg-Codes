class Solution {
public:
    // int check(vector<int>& gas, vector<int>& cost,int k,int i,int tank,int n){
    // //    if(tank<cost[i]){
    // //      return -1;
    // //    }
    // //    if(i==k){
    // //     return k;
    // //    }
    // //    return check(gas,cost,k,(i+1)%n,tank-cost[i]+gas[(i+1)%n],n);

    //  while(i!=k){
    //     if(tank<cost[i]){
    //         return -1;
    //     }
    //     tank=tank-cost[i]+gas[(i+1)%n];
    //     i=(i+1)%n;
    //  }
    //  return k;
    // }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //method 1
        //brute force
        // int ans=-1;
        // int n=gas.size();
        // for(int i=0;i<gas.size();i++){
        //     int tank=gas[i];
        //      if(tank<cost[i]){
        //        ans=-1;
        //        continue;
        //     }
        //    tank=tank-cost[i]+gas[(i+1)%n];
        //    ans=check(gas,cost,i,(i+1)%n,tank,n);
        //    if(ans!=-1){
        //     break;
        //    }
        // }
        // return ans;

        //method 2
        int balance=0;
        int deficient=0;
        int start=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            balance=balance+gas[i]-cost[i];
            if(balance<0){
                deficient=deficient+balance;
                start=i+1;
                balance=0;
            }
        }
        if(balance+deficient>=0){
            return start;
        }
        return -1;
    }
};