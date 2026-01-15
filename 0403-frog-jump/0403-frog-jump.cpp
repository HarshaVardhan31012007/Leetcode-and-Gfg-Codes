class Solution {
public:
    unordered_map<int,int>mpp;
    bool solve(vector<int>&stones,int prev,int i,vector<vector<int>>&dp){
        if(i==stones.size()-1) return true;
        if(dp[i][prev]!=-1) return dp[i][prev];
        bool ans=false;
        int diff=stones[i]-stones[prev];
        if(mpp.count(stones[i]+diff-1)&&mpp[stones[i]+diff-1]>i){
            ans=ans||solve(stones,i,mpp[stones[i]+diff-1],dp);
        }
        if(mpp.count(stones[i]+diff)&&mpp[stones[i]+diff]>i){
            ans=ans||solve(stones,i,mpp[stones[i]+diff],dp);
        }
        if(mpp.count(stones[i]+diff+1)&&mpp[stones[i]+diff+1]>i){
            ans=ans||solve(stones,i,mpp[stones[i]+diff+1],dp);
        }
        return dp[i][prev]=ans;
    }
    bool canCross(vector<int>& stones) {
        for(int i=0;i<stones.size();i++)
        mpp[stones[i]]=i;
        vector<vector<int>>dp(stones.size()+1,vector<int>(stones.size()+1,-1));
        if(stones[1]>1) return false;
        return solve(stones,0,1,dp);
    }
};