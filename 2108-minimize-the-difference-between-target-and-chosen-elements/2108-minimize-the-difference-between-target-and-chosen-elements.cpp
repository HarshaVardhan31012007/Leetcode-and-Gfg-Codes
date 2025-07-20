class Solution {
public:
    int solve(vector<vector<int>>& mat, int sum,int i,int target,vector<vector<int>>&dp){
        if(i==mat.size()) return abs(target-sum);
        if(dp[i][sum]!=-1) return dp[i][sum];
        int ans=INT_MAX;
        for(int j=0;j<mat[i].size();j++){
            int recAns=solve(mat,sum+mat[i][j],i+1,target,dp);
            ans=min(ans,recAns);
        }
        return dp[i][sum]=ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {

       vector<vector<int>>dp(mat.size()+1,vector<int>(5000,-1));
       return solve(mat,0,0,target,dp);
    }
};