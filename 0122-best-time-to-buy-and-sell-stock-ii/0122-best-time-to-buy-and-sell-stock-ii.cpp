class Solution {
public:
    // int solve(vector<int>&prices,int i,int flag,vector<vector<int>>&dp){
    //     if(i>=prices.size()) return 0;
    //     if(dp[i][flag]!=-1) return dp[i][flag];
    //     int ans=0;
    //     //buy
    //     if(flag==0)
    //     ans=max(ans,-prices[i]+solve(prices,i+1,1,dp));
    //     //sell
    //     if(flag==1)
    //     ans=max(ans,prices[i]+solve(prices,i+1,0,dp));
    //     //skip
    //     ans=max(ans,solve(prices,i+1,flag,dp));
    //     return dp[i][flag]=ans;
    // }
    // int maxProfit(vector<int>& prices) {
    //     vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
    //     return solve(prices,0,0,dp);
    // }



   
    int maxProfit(vector<int>& prices) {
        int ans=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1])
            ans+=prices[i]-prices[i-1];
        }
        return ans;
    }
};