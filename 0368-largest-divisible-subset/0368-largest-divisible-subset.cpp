class Solution {
public:
    int solve(vector<int>&nums,int i,int prev,vector<vector<int>>&dp){
        if(i>=nums.size()) return dp[i][prev+1]=0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int inc=0;
        if(prev==-1||nums[i]%nums[prev]==0){
            inc=1+solve(nums,i+1,i,dp);
        }
        int exc=solve(nums,i+1,prev,dp);
        return dp[i][prev+1]=max(inc,exc);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        solve(nums,0,-1,dp);
        int i=0;int prev=-1;
        vector<int>ans;
        while(i<nums.size()){
            if(dp[i][prev+1]!=dp[i+1][prev+1]){
                ans.push_back(nums[i]);
                prev=i;
            }
            i++;
        }
        return ans;
    }
};