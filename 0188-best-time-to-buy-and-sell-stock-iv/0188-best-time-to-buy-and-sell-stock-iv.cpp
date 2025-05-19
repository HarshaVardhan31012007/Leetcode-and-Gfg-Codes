class Solution {
public:
      int solve(vector<int>&prices,int k){
          vector<vector<int>>curr(2,vector<int>(k+1,0));
          vector<vector<int>>next(2,vector<int>(k+1,0));
        for(int i=prices.size()-1;i>=0;i--){
            for(int flag=0;flag<=1;flag++){
                for(int limit=1;limit<=k;limit++){
        int profit=0;
        if(flag)
         profit=max(profit,-prices[i]+next[0][limit]);
         else
        profit=max(profit,prices[i]+next[1][limit-1]);
        profit=max(profit,next[flag][limit]);
        curr[flag][limit]=profit;
                }
            }
            next=curr;
        }
        return curr[1][k];
     }
    int maxProfit(int k, vector<int>& prices) {
         return solve(prices,k);
    }
};