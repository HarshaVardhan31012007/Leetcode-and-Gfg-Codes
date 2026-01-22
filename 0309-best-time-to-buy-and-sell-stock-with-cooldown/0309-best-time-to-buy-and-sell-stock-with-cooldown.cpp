class Solution {
public:
    int solve(vector<int>&prices,int i,int flag,vector<vector<int>>&dp){
        if(i>=prices.size()) return 0;
        if(dp[i][flag]!=-1) return dp[i][flag];
        int ans=0;
        if(flag){
           ans=max(ans,prices[i]+solve(prices,i+2,0,dp));
        }
        else{
            ans=max(ans,-prices[i]+solve(prices,i+1,1,dp));
        }
        ans=max(ans,solve(prices,i+1,flag,dp));
        return dp[i][flag]=ans;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(prices,0,0,dp);
    }
};