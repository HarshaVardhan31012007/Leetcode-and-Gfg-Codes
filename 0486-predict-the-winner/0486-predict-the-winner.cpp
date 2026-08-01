// class Solution {
// public:
//     int solve(vector<int>&nums,int s,int e,int turn,vector<vector<vector<int>>>&dp){
//         if(s==e) return nums[s];
//         if(dp[s][e][turn]!=-1) return dp[s][e][turn];
//         int ans=(turn?INT_MAX:INT_MIN);
//         if(turn){
//             ans=min(ans,solve(nums,s+1,e,!turn,dp));
//             ans=min(ans,solve(nums,s,e-1,!turn,dp));
//         }   
//         else{
//             ans=max(ans,nums[s]+solve(nums,s+1,e,!turn,dp));
//             ans=max(ans,nums[e]+solve(nums,s,e-1,!turn,dp));
//         }
//         return dp[s][e][turn]=ans;
//     }
//     bool predictTheWinner(vector<int>& nums) {
//         int n=nums.size();
//         int total=accumulate(nums.begin(),nums.end(),0);
//         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
//         int player1=solve(nums,0,n-1,0,dp);
//         int player2=total-player1;
//         return player1>=player2;
//     }
// };



class Solution {
public:
    int solve(vector<int>&nums,int s,int e,vector<vector<int>>&dp){
        if(s==e) return nums[s];
        if(dp[s][e]!=-1) return dp[s][e];
        return dp[s][e]=max(nums[s]-solve(nums,s+1,e,dp),nums[e]-solve(nums,s,e-1,dp));
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums,0,n-1,dp)>=0;
    }
};