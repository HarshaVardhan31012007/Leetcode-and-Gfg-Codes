class Solution {
public:
    int solve(vector<int>& values,int s,int e,vector<vector<int>>&dp){
        if(s+1==e) return 0;
        if(dp[s][e]!=-1) return dp[s][e];
        int ans=INT_MAX;
        for(int j=s+1;j<e;j++){
            ans=min(ans,values[s]*values[e]*values[j]+solve(values,s,j,dp)+solve(values,j,e,dp));
        }
        return dp[s][e]=ans;
    }
    int minScoreTriangulation(vector<int>& values) {
       vector<vector<int>>dp(values.size()+1,vector<int>(values.size()+1,-1));
       return solve(values,0,values.size()-1,dp);
    }
};