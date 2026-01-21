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


    // int solve(vector<int>&coins,int amount,vector<int>&dp){
    //     if(amount==0){
    //         return 0;
    //     }
    //     if(dp[amount]!=-1)
    //     return dp[amount];
    //     int mini=INT_MAX;
    //     for(auto &each:coins){
    //           if(each<=amount){
    //         int curr=solve(coins,amount-each,dp);
    //         if(curr!=INT_MAX)
    //         mini=min(mini,1+curr);
    //          }
    //     }
    //     return dp[amount]=mini;
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //      vector<int>dp(amount+1,-1);
    //     int mini=solve(coins,amount,dp);
    //     return (mini==INT_MAX)?-1:mini;
    // }



    // int solve(vector<int>&coins,int amount){
    //     vector<int>dp(amount+1,INT_MAX);
    //     dp[0]=0;
    //     for(int a=1;a<amount+1;a++){
    //         for(auto &each:coins){
    //             if(each<=a&&dp[a-each]!=INT_MAX)
    //             dp[a]=min(dp[a],1+dp[a-each]);
    //         }
    //     }
    //     return dp[amount];
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int mini=solve(coins,amount);
    //     return (mini==INT_MAX)?-1:mini;
    // }


    // int solve(vector<int>&coins,int amount,vector<int>&dp){
    //     if(amount==0) return 0;
    //     if(dp[amount]!=-1) return dp[amount];
    //     int mini=INT_MAX;
    //     for(auto &each:coins){
    //         if(each<=amount){
    //             int recans=solve(coins,amount-each,dp);
    //             if(recans!=INT_MAX)
    //             mini=min(mini,1+recans);
    //         }
    //     }
    //     return dp[amount]=mini;
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     vector<int>dp(amount+1,-1);
    //     int mini=solve(coins,amount,dp);
    //     return (mini==INT_MAX)?-1:mini;
    // }



    int solve(vector<int>&coins,int i,int amount,vector<vector<int>>&dp){
        if(amount==0) return 0;
        if(i>=coins.size()) return INT_MAX;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int inc=INT_MAX;
        if(amount>=coins[i]){
            int reccall=solve(coins,i,amount-coins[i],dp);
            if(reccall!=INT_MAX)
            inc=1+reccall;
        }
        int exc=solve(coins,i+1,amount,dp);
        return dp[i][amount]=min(inc,exc);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int mini=solve(coins,0,amount,dp);
        return (mini==INT_MAX)?-1:mini;
    }
};