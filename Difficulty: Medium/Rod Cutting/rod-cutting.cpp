// User function Template for C++

class Solution {
  public:
    int solve(int len,vector<int>&price,vector<int>&dp){
        if(len==0) return 0;
        if(dp[len]!=-1) return dp[len];
        int ans=0;
        for(int i=1;i<=len;i++){
             if(len>=i)
             ans=max(ans,price[i-1]+solve(len-i,price,dp));
        }
        return dp[len]=ans;
    }
    int cutRod(vector<int> &price) {
        vector<int>dp(price.size()+1,-1);
        return solve(price.size(),price,dp);
    }
};