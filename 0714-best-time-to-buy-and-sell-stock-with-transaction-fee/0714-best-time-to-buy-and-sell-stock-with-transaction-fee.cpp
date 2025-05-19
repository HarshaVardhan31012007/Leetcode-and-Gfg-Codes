class Solution {
public:
    //   int solve(vector<int>&prices,int i,int flag,int fee,vector<vector<int>>&dp){
    //     if(i==prices.size()) return 0;
    //     if(dp[i][flag]!=-1) return dp[i][flag];
    //     int profit=0;
    //     if(flag)
    //      profit=max(profit,-prices[i]+solve(prices,i+1,0,fee,dp));
    //      else
    //     profit=max(profit,prices[i]-fee+solve(prices,i+1,1,fee,dp));
    //     profit=max(profit,solve(prices,i+1,flag,fee,dp));
    //     return dp[i][flag]=profit;
    //  }
    //  int maxProfit(vector<int>& prices,int fee) {
    //     vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
    //     return solve(prices,0,1,fee,dp);
    //  }

     int solve(vector<int>&prices,int fee){
         vector<int>curr(2,0);
         vector<int>next(2,0);
         for(int i=prices.size()-1;i>=0;i--){
            for(int flag=0;flag<=1;flag++){
                int profit=0;
                if(flag)
                profit=max(profit,-prices[i]+next[0]);
                else
                profit=max(profit,prices[i]-fee+next[1]);
                profit=max(profit,next[flag]);
                curr[flag]=profit;
            }
            next=curr;
         }
         return curr[1];
     }
     int maxProfit(vector<int>& prices,int fee) {
        return solve(prices,fee);
     }
};