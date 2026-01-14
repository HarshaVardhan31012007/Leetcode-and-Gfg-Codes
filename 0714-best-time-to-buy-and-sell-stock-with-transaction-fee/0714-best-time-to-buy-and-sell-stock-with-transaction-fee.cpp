class Solution {
public:
    int solve(vector<int>&prices,int i,int flag,int fee,vector<vector<int>>&dp){
        if(i>=prices.size()) return 0;
        if(dp[i][flag]!=-1) return dp[i][flag];
        int ans=0;
        //buy
        if(flag==0)
        ans=max(ans,-prices[i]+solve(prices,i+1,1,fee,dp));
        //sell
        if(flag==1)
        ans=max(ans,prices[i]-fee+solve(prices,i+1,0,fee,dp));
        //skip
        ans=max(ans,solve(prices,i+1,flag,fee,dp));
        return dp[i][flag]=ans;
    }
    int maxProfit(vector<int>& prices,int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,0,fee,dp);
    }
};