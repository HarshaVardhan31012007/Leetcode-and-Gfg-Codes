class Solution {
public:
    int solve(vector<int>&piles,int i,int j,vector<vector<int>>&dp){
       if(i>j) return 0;
       if(dp[i][j]!=-1) return dp[i][j];
       int l=piles[i]+max(solve(piles,i+2,j,dp),solve(piles,i+1,j-1,dp));
       int r=piles[j]+max(solve(piles,i+1,j-1,dp),solve(piles,i,j-2,dp));
       return dp[i][j]=max(l,r);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int sum=accumulate(piles.begin(),piles.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solve(piles,0,n-1,dp);
        return ans>sum-ans;
    }

    // bool stoneGame(vector<int>&piles){
    //     return 1;
    // }
};