class Solution {
public:
    // pair<int,int>solve(vector<int>&nums,int i,int prev,vector<vector<pair<int,int>>>&dp){
    //     if(i>=nums.size()) return {0,1};
    //     if(dp[i][prev+1]!=make_pair(-1,-1)) return dp[i][prev+1];
    //     pair<int,int>l={INT_MIN,0};
    //     if(prev==-1||nums[i]>nums[prev]){
    //         auto reccall=solve(nums,i+1,i,dp);
    //         l.first=1+reccall.first;
    //         l.second=reccall.second;
    //     }
    //     pair<int,int>r=solve(nums,i+1,prev,dp);
    //     if(l.first>r.first){
    //         return dp[i][prev+1]=l;
    //     }
    //     else if(r.first>l.first){
    //         return dp[i][prev+1]=r;
    //     }
    //     return dp[i][prev+1]={l.first,l.second+r.second};
    // }
    // int findNumberOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<pair<int,int>>>dp(n+1,vector<pair<int,int>>(n+1,make_pair(-1,-1)));
    //     auto ans=solve(nums,0,-1,dp);
    //     return ans.second;
    // }




    
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]&&dp[j]+1>dp[i]){
                    dp[i]=1+dp[j];
                    cnt[i]=cnt[j];
                }
                else if(nums[j]<nums[i]&&dp[j]+1==dp[i]){
                    cnt[i]+=cnt[j];
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                ans+=cnt[i];
            }
        }
        return ans;
    }
};