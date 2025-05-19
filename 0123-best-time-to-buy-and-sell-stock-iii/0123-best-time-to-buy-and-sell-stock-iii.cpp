class Solution {
public:
       int solve(vector<int>&prices,int i,int flag,vector<vector<vector<int>>>&dp,int limit){
        if(i==prices.size()||limit==0) return 0;
        if(dp[i][flag][limit]!=-1) return dp[i][flag][limit];
        int profit=0;
        if(flag)
         profit=max(profit,-prices[i]+solve(prices,i+1,0,dp,limit));
         else
        profit=max(profit,prices[i]+solve(prices,i+1,1,dp,limit-1));
        profit=max(profit,solve(prices,i+1,flag,dp,limit));
        return dp[i][flag][limit]=profit;
     }
     int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,1,dp,2);
     }


   
};