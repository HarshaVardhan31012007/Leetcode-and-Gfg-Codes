class Solution {
public:
    // int solve(vector<int>&nums,int p,int i,int d,int D,vector<vector<vector<int>>>&dp){
    //     if(i==nums.size()) return 0;
    //     if(dp[i][p+1][d+D]!=-1) return dp[i][p+1][d+D];
    //     int ans=INT_MIN;
    //     if(p==-1)
    //     ans=max(ans,1+solve(nums,i,i+1,d,D,dp));
    //     else if(d==D+1||nums[i]-nums[p]==d)
    //     ans=max(ans,1+solve(nums,i,i+1,nums[i]-nums[p],D,dp));
    //     ans=max(ans,solve(nums,p,i+1,d,D,dp));
    //     return dp[i][p+1][d+D]=ans;
    // }
    // int longestArithSeqLength(vector<int>& nums) {
    //     int D=*max_element(nums.begin(),nums.end())-*min_element(nums.begin(),nums.end());
    //     vector<vector<vector<int>>>dp(nums.size()+1,vector<vector<int>>(nums.size()+1,vector<int>(2*D+2,-1)));
    //     return solve(nums,-1,0,D+1,D,dp);
    // }



    // int solve(vector<int>&nums,int i,int d,unordered_map<int,int>dp[]){
    //     if(dp[i].count(d)==1) return dp[i][d];
    //     int ans=0;
    //     for(int j=i+1;j<nums.size();j++){
    //         if(nums[j]-nums[i]==d)
    //         ans=max(ans,1+solve(nums,j,d,dp));
    //     }
    //     return dp[i][d]=ans;
    // }
    // int longestArithSeqLength(vector<int>& nums) {
    //     if(nums.size()<=2) return nums.size();
    //     unordered_map<int,int>dp[nums.size()];
    //     int ans=0;
    //    for(int i=0;i<nums.size();i++){
    //     for(int j=i+1;j<nums.size();j++){
    //       ans=max(ans,2+solve(nums,j,nums[j]-nums[i],dp));
    //     }
    //    }
    //    return ans;
    // }


     
   
    int longestArithSeqLength(vector<int>& nums) {
        if(nums.size()<=2) return nums.size();
        unordered_map<int,int>dp[nums.size()+1];
        int ans=0;
       for(int i=1;i<nums.size();i++){
        for(int j=0;j<i;j++){
            int cnt=1;
            if(dp[j].count(nums[j]-nums[i]))
            cnt=dp[j][nums[j]-nums[i]];
            dp[i][nums[j]-nums[i]]=1+cnt;
            ans=max(ans,dp[i][nums[j]-nums[i]]);
        }
       }
       return ans;
    }

};