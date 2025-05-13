class Solution {
public:
    // int solve(vector<int>& arr,int n,int i,int flag,vector<vector<int>>&dp){
    //     if(i==arr.size()) return 0;
    //     if(dp[i][flag]!=-1) return dp[i][flag];
    //     int total=0;
    //     int ans=flag==1?INT_MIN:INT_MAX;
    //     for(int j=0;j<3;j++){
    //      if(i+j>=arr.size()) break;
    //      total+=arr[i+j];
    //      if(flag)
    //      ans=max(ans,total+solve(arr,n,i+j+1,!flag,dp));
    //      else
    //      ans=min(ans,-total+solve(arr,n,i+j+1,!flag,dp));
    //     }
    //     return dp[i][flag]=ans;
    // }
    // string stoneGameIII(vector<int>& stoneValue) {
    //    int n=stoneValue.size();
    //    vector<vector<int>>dp(n+1,vector<int>(2,-1));
    //    int ans=solve(stoneValue,n,0,1,dp);
    //    if(ans>0)
    //    return "Alice";
    //    else if(ans<0)
    //    return "Bob";
    //    else
    //    return "Tie";
    // }


    // int solve(vector<int>& arr){
    //    int n=arr.size();
    //    vector<vector<int>>dp(n+1,vector<int>(2,0));
    //    for(int i=n-1;i>=0;i--){
    //     for(int flag=0;flag<=1;flag++){
    //     int total=0;
    //     int ans=flag==1?INT_MIN:INT_MAX;
    //     for(int j=0;j<3;j++){
    //      if(i+j>=arr.size()) break;
    //      total+=arr[i+j];
    //      if(flag)
    //      ans=max(ans,total+dp[i+j+1][!flag]);
    //      else
    //      ans=min(ans,-total+dp[i+j+1][!flag]);
    //     }
    //     dp[i][flag]=ans;
    //     }
    //    }
    //    return dp[0][1];
    // }
    // string stoneGameIII(vector<int>& stoneValue) {
    //    int ans=solve(stoneValue);
    //    if(ans>0)
    //    return "Alice";
    //    else if(ans<0)
    //    return "Bob";
    //    else
    //    return "Tie";
    // }


    int solve(vector<int>& arr){
       int n=arr.size();
       vector<int>dp(n+1,0);
       for(int i=n-1;i>=0;i--){
        int total=0;
        int ans=INT_MIN;
        for(int j=0;j<3;j++){
         if(i+j>=arr.size()) break;
         total+=arr[i+j];
         ans=max(ans,total-dp[i+j+1]);
        }
        dp[i]=ans;
        }
       return dp[0];
    }
    string stoneGameIII(vector<int>& stoneValue) {
       int ans=solve(stoneValue);
       if(ans>0)
       return "Alice";
       else if(ans<0)
       return "Bob";
       else
       return "Tie";
    }
};