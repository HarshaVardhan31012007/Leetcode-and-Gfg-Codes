class Solution {
public:
    // void solve(vector<int>&coins,int amount,int ans,int &mini){
    //     if(amount<0) return;
    //     if(amount==0){
    //         mini=min(mini,ans);
    //         return;
    //     }
    //     for(auto &each:coins){
    //         solve(coins,amount-each,ans+1,mini);
    //     }
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int ans=0;int mini=INT_MAX;
    //     solve(coins,amount,ans,mini);
    //     return (mini==INT_MAX)?-1:mini;
    // }


    int solve(vector<int>&coins,int amount,vector<int>&dp){
        if(amount<0) return INT_MAX;
        if(amount==0){
            return 0;
        }
        if(dp[amount]!=-1)
        return dp[amount];
        int mini=INT_MAX;
        for(auto &each:coins){
            int curr=solve(coins,amount-each,dp);
            if(curr!=INT_MAX)
            mini=min(mini,1+curr);
        }
        return dp[amount]=mini;
    }
    int coinChange(vector<int>& coins, int amount) {
         vector<int>dp(amount+1,-1);
        int mini=solve(coins,amount,dp);
        return (mini==INT_MAX)?-1:mini;
    }
};