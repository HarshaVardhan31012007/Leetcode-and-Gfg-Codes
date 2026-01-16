class Solution {
  public:
    int solve(vector<vector<int>>&arr,int prev,int i,vector<vector<int>>&dp){
        if(i>=arr.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int one=INT_MIN,two=INT_MIN,three=INT_MIN;
        if(prev!=0)
        one=arr[i][0]+solve(arr,0,i+1,dp);
        if(prev!=1)
        two=arr[i][1]+solve(arr,1,i+1,dp);
        if(prev!=2)
        three=arr[i][2]+solve(arr,2,i+1,dp);
        return dp[i][prev+1]=max(one,max(two,three));
    }
    int maximumPoints(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(4,-1));
        return solve(arr,-1,0,dp);
    }
};