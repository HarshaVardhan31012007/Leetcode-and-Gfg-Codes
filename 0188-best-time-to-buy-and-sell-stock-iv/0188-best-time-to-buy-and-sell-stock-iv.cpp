class Solution {
public:
    //  int solve(vector<int>&prices,int i,int flag,int c,int k,vector<vector<vector<int>>>&dp){
    //     if(i>=prices.size()) return 0;
    //     if(dp[i][flag][c]!=-1) return dp[i][flag][c];
    //     int ans=0;
    //     //buy
    //     if(flag==0)
    //     ans=max(ans,-prices[i]+solve(prices,i+1,1,c,k,dp));
    //     //sell
    //     if(flag==1&&c<k)
    //     ans=max(ans,prices[i]+solve(prices,i+1,0,c+1,k,dp));
    //     //skip
    //     ans=max(ans,solve(prices,i+1,flag,c,k,dp));
    //     return dp[i][flag][c]=ans;
    // }
    // int maxProfit(int k,vector<int>& prices) {
    //     vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
    //     return solve(prices,0,0,0,k,dp);
    // }




     int solve(vector<int>&prices,int i,int c,int k,vector<vector<int>>&dp){
        if(i>=prices.size()) return 0;
        if(dp[i][c]!=-1) return dp[i][c];
        int ans=0;
        //buy
        if(!(c&1))
        ans=max(ans,-prices[i]+solve(prices,i+1,c+1,k,dp));
        //sell
        if((c&1)&&c<2*k)
        ans=max(ans,prices[i]+solve(prices,i+1,c+1,k,dp));
        //skip
        ans=max(ans,solve(prices,i+1,c,k,dp));
        return dp[i][c]=ans;
    }
    int maxProfit(int k,vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2*k+2,-1));
        return solve(prices,0,0,k,dp);
    }
};