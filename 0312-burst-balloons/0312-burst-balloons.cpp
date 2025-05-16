class Solution {
public:
    // map<vector<int>,int>dp;
    // int solve(vector<int>&arr){
    //     if(arr.size()==0) return 0;
    //     if(dp.find(arr)!=dp.end()) return dp[arr];
    //     int ans=INT_MIN;
    //     int n=arr.size();
    //     for(int i=0;i<n;i++){
    //         int t=arr[i];
    //         int prev=i-1>=0?arr[i-1]:1;
    //         int curr=i+1<n?arr[i+1]:1;
    //         arr.erase(arr.begin()+i);
    //         ans=max(ans,prev*t*curr+solve(arr));
    //         arr.insert(arr.begin()+i,t);
    //     }
    //     return dp[arr]=ans;
    // }
    // int maxCoins(vector<int>& nums) {
    //    return solve(nums); 
    // }

    // int solve(vector<int>&nums,int s,int e,vector<vector<int>>&dp){
    //     if(s>e) return 0;
    //     if(dp[s][e]!=-1) return dp[s][e];
    //     int ans=INT_MIN;
    //     for(int i=s;i<=e;i++){
    //         ans=max(ans,nums[s-1]*nums[i]*nums[e+1]+solve(nums,s,i-1,dp)+solve(nums,i+1,e,dp));
    //     }
    //     return dp[s][e]=ans;
    // }
    // int maxCoins(vector<int>& nums) {
    //    nums.insert(nums.begin(),1);
    //    nums.insert(nums.end(),1);
    //    int n=nums.size();
    //    vector<vector<int>>dp(n,vector<int>(n,-1));
    //    return solve(nums,1,n-2,dp); 
    // }


     int solve(vector<int>&nums){
       nums.insert(nums.begin(),1);
       nums.insert(nums.end(),1);
       int n=nums.size();
       vector<vector<int>>dp(n,vector<int>(n,0));
       for(int s=n-2;s>=1;s--){
        for(int e=s;e<=n-2;e++){
        int ans=INT_MIN;
        for(int i=s;i<=e;i++){
            ans=max(ans,nums[s-1]*nums[i]*nums[e+1]+dp[s][i-1]+dp[i+1][e]);
        }
        dp[s][e]=ans;
        }
       }
       return dp[1][n-2];
    }
    int maxCoins(vector<int>& nums) {
       return solve(nums); 
    }
};