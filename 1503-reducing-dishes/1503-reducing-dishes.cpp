class Solution {
public:
    int solve(vector<int>&satisfaction,int i,int time,vector<vector<int>>&dp){
        if(i==satisfaction.size()) return 0;
        if(dp[i][time]!=-1) return dp[i][time];
         int l=satisfaction[i]*time+solve(satisfaction,i+1,time+1,dp);
         int r=0;
        // if(satisfaction[i]<0)//optimization
        r=solve(satisfaction,i+1,time,dp);
        return dp[i][time]=max(l,r);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>>dp(satisfaction.size()+1,vector<int>(satisfaction.size()+1,-1));
        return solve(satisfaction,0,1,dp);
    }
};