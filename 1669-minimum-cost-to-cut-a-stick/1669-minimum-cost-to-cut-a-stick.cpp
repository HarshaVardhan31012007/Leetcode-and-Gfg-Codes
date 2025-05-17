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
    //   for(int i=n;i>=0;i--){
    //     for(int j=i;j<=n;j++){
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


    int solve(vector<int>&cuts,int s,int e,vector<vector<int>>&dp){
       if(e-s==1) return 0;
       if(dp[s][e]!=-1) return dp[s][e];
        int ans=INT_MAX;
        for(int i=s+1;i<e;i++){
           ans=min(ans,cuts[e]-cuts[s]+solve(cuts,s,i,dp)+solve(cuts,i,e,dp));
        }
        return dp[s][e]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.insert(cuts.end(),n);
        int m=cuts.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return solve(cuts,0,m-1,dp);
    }
};