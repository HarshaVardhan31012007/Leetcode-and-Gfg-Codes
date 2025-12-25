class Solution {
  public:
    int solve(int i,vector<int>&val,vector<int>&wt,int W,vector<vector<int>>&dp){
        if(i==0){
            if(wt[i]<=W){
                return val[0];
            }
            else
            return 0;
        }
        if(dp[i][W]!=-1) return dp[i][W];
        int inc=0;
        if(wt[i]<=W){
            inc=val[i]+solve(i-1,val,wt,W-wt[i],dp);
        }
        int exc=solve(i-1,val,wt,W,dp);
        return dp[i][W]=max(inc,exc);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<vector<int>>dp(val.size()+1,vector<int>(W+1,-1));
        return solve(val.size()-1,val,wt,W,dp);
    }
};