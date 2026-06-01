class Solution {
public:
    int minimumCost(vector<int>& cost) {
        // sort(cost.begin(),cost.end());
        // int n=cost.size();
        // int ans=0;
        // int c=3;
        // for(int i=n-1;i>=0;i--){
        //     c--;
        //     if(c==0){
        //         c=3;
        //         continue;
        //     }
        //     ans+=cost[i];
        // }
        // return ans;


        sort(cost.begin(),cost.end());
        int n=cost.size();
        int ans=0;
        for(int i=n;i>=1;i--){
           if((n-i+1)%3!=0){
              ans+=cost[i-1];
           }
        }
        return ans;
    }
};