class Solution {
public:
    int solve(vector<int>&slices,int i,int end,int n,vector<vector<int>>&dp){
       if(i>end||n==0) return 0;
       if(dp[i][n]!=-1) return dp[i][n];
       int inc=slices[i]+solve(slices,i+2,end,n-1,dp);
       int exc=solve(slices,i+1,end,n,dp);
       return dp[i][n]=max(inc,exc);
    }
    int maxSizeSlices(vector<int>& slices) {
        vector<vector<int>>dp1(slices.size()+1,vector<int>(slices.size()/3+1,-1));
        vector<vector<int>>dp2(slices.size()+1,vector<int>(slices.size()/3+1,-1));
        return max(slices[0]+solve(slices,2,slices.size()-2,slices.size()/3-1,dp1),solve(slices,1,slices.size()-1,slices.size()/3,dp2));
    }
};