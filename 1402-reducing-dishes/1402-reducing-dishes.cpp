class Solution {
public:
    int solve(vector<int>&arr,int i,int time,int n,vector<vector<int>>&dp){
        if(i>=n) return 0;
        if(dp[i][time]!=-1) return dp[i][time];
        int inc=arr[i]*time+solve(arr,i+1,time+1,n,dp);
        int exc=0;
        if(arr[i]<0)
        exc=solve(arr,i+1,time,n,dp);
        return dp[i][time]=max(inc,exc);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        sort(satisfaction.begin(),satisfaction.end());
        return solve(satisfaction,0,1,n,dp);
    }
};