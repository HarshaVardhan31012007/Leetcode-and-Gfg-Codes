class Solution {
public:
    // int solve(vector<int>&cuts,int s,int e,vector<vector<int>>&dp){
    //     if(dp[s][e]!=-1)
    //     return dp[s][e];
    //     int ans=INT_MAX;
    //     for(auto &cut:cuts){
    //       if(cut>s&&cut<e)
    //       ans=min(ans,e-s+solve(cuts,s,cut,dp)+solve(cuts,cut,e,dp));
    //     }
    //     return dp[s][e]=(ans==INT_MAX)?0:ans;
    // }
    // int minCost(int n, vector<int>& cuts) {
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //     return solve(cuts,0,n,dp);
    // }


    // int solve(vector<int>&cuts,int n){
    //   vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //   for(int i=n-1;i>=0;i--){
    //     for(int j=i;j<=n-1;j++){
    //     int ans=INT_MAX;
    //     for(auto &cut:cuts){
    //       if(cut>i&&cut<j)
    //       ans=min(ans,j-i+dp[i][cut]+dp[cut][j]);
    //     }
    //     dp[i][j]=(ans==INT_MAX)?0:ans;
    //     }
    //   }
    //   return dp[0][n];
    // }
    // int minCost(int n, vector<int>& cuts) {
    //     return solve(cuts,n);
    // }


    int minCost(int n, vector<int>& cuts) {
        // Step 1: Add 0 and n to the cuts and sort
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        int c = cuts.size();
        vector<vector<int>> dp(c, vector<int>(c, 0));
        
        // Step 2: Fill DP table in bottom-up manner
        for (int len = 2; len < c; ++len) {
            for (int i = 0; i + len < c; ++i) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
                }
            }
        }
        
        return dp[0][c - 1];
    }
};