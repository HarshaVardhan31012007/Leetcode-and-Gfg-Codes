class Solution {
public:
    //    int solve(vector<int>&prices,int i,int flag,vector<vector<vector<int>>>&dp,int limit){
    //     if(i==prices.size()||limit==0) return 0;
    //     if(dp[i][flag][limit]!=-1) return dp[i][flag][limit];
    //     int profit=0;
    //     if(flag)
    //      profit=max(profit,-prices[i]+solve(prices,i+1,0,dp,limit));
    //      else
    //     profit=max(profit,prices[i]+solve(prices,i+1,1,dp,limit-1));
    //     profit=max(profit,solve(prices,i+1,flag,dp,limit));
    //     return dp[i][flag][limit]=profit;
    //  }
    //  int maxProfit(vector<int>& prices) {
    //     vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
    //     return solve(prices,0,1,dp,2);
    //  }

   
       int solve(vector<int>&prices){
          vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=prices.size()-1;i>=0;i--){
            for(int flag=0;flag<=1;flag++){
                for(int limit=1;limit<=2;limit++){
        int profit=0;
        if(flag)
         profit=max(profit,-prices[i]+dp[i+1][0][limit]);
         else
        profit=max(profit,prices[i]+dp[i+1][1][limit-1]);
        profit=max(profit,dp[i+1][flag][limit]);
        dp[i][flag][limit]=profit;
                }
            }
        }
        return dp[0][1][2];
     }
     int maxProfit(vector<int>& prices) {
        return solve(prices);
     }
   
};