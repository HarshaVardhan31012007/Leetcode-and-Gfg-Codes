class Solution {
  public:
    int solve(vector<int>&val,vector<int>&wt,int i,int capacity,vector<vector<int>>&dp){
        if(i>=val.size()) return 0;
        if(dp[i][capacity]!=-1) return dp[i][capacity];
        int inc=0;
        if(wt[i]<=capacity)
        inc=val[i]+solve(val,wt,i,capacity-wt[i],dp);
        int exc=solve(val,wt,i+1,capacity,dp);
        return dp[i][capacity]=max(inc,exc);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<vector<int>>dp(val.size()+1,vector<int>(capacity+1,-1));
        return solve(val,wt,0,capacity,dp);
    }
};