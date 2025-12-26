class Solution {
public:
    pair<int,int>solve(vector<int>&arr,int s,int e,vector<vector<pair<int,int>>>&dp){
        if(s==e) return {arr[s],0};
        if(dp[s][e].first!=-1&&dp[s][e].second!=-1) return dp[s][e];
        int ans=INT_MAX;
        int curr=INT_MIN;
        for(int i=s;i<e;i++){
           auto l=solve(arr,s,i,dp);
           auto r=solve(arr,i+1,e,dp);
           int c=l.first*r.first+l.second+r.second;
           if(c<ans){
             ans=c;
             curr=max(l.first,r.first);
           }
        }
        return dp[s][e]={curr,ans};
    }
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<pair<int,int>>>dp(arr.size()+1,vector<pair<int,int>>(arr.size()+1,{-1,-1}));
        auto ans=solve(arr,0,arr.size()-1,dp);
        return ans.second;
    }
};