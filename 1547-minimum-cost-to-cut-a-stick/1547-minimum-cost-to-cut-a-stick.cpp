class Solution {
public:
    //  int solve(vector<int>&cuts,int s,int e,vector<vector<int>>&dp){
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



    int solve(vector<int>&cuts,int i,int j,vector<vector<int>>&dp){
        if(j-i+1<=2) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            ans=min(ans,cuts[j]-cuts[i]+solve(cuts,i,k,dp)+solve(cuts,k,j,dp));
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n); 
        int m=cuts.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        return solve(cuts,0,m-1,dp);
    }
};