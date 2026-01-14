class Solution {
public:
    int solve(vector<int>&prices,int i,int flag,int c,vector<vector<vector<int>>>&dp){
        if(i>=prices.size()) return 0;
        if(dp[i][flag][c]!=-1) return dp[i][flag][c];
        int ans=0;
        //buy
        if(flag==0)
        ans=max(ans,-prices[i]+solve(prices,i+1,1,c,dp));
        //sell
        if(flag==1&&c<2)
        ans=max(ans,prices[i]+solve(prices,i+1,0,c+1,dp));
        //skip
        ans=max(ans,solve(prices,i+1,flag,c,dp));
        return dp[i][flag][c]=ans;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,0,0,dp);
    }
};