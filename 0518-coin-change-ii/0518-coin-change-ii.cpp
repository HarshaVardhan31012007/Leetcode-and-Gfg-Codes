class Solution {
public:
    int solve(vector<int>&coins,int i,int amount,vector<vector<int>>&dp){
        if(amount==0) return 1;
        if(i>=coins.size()) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int ans=0;
        for(int j=i;j<coins.size();j++){
            if(coins[j]<=amount){
                ans+=solve(coins,j,amount-coins[j],dp);
            }
        }
        return dp[i][amount]=ans;
    }
    int change(int amount,vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int mini=solve(coins,0,amount,dp);
        return (mini==INT_MAX)?-1:mini;
    }
};