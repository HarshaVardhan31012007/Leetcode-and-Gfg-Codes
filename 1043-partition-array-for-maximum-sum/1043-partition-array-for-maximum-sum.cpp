class Solution {
public:
    int solve(vector<int>&arr,int i,int k,vector<int>&dp){
        if(i>=arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi=INT_MIN;int ans=INT_MIN;
        for(int j=0;j<k&&i+j<arr.size();j++){
            maxi=max(maxi,arr[i+j]);
            ans=max(ans,maxi*(j+1)+solve(arr,i+j+1,k,dp));
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return solve(arr,0,k,dp);
    }
};