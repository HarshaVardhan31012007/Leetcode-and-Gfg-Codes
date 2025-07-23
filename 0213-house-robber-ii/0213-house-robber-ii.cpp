class Solution {
public:
        int findmax(vector<int>&nums,int s,int e,vector<vector<int>>&dp){

       //base case
       if(s>e){
         return 0;
       }
       if(dp[s][e]!=-1)
       return dp[s][e];
       //include
       int includekaAns=nums[s]+findmax(nums,s+2,e,dp);
       //exclude
       int excludekaAns=0+findmax(nums,s+1,e,dp);
       int finalAns=max(includekaAns,excludekaAns);
       return dp[s][e]=finalAns;

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        // as n-1,0 are adjacent we cannot rob both 
        //one case we caanot n-1
        //other case is we cananot rob 0
        // int ans1=findmax(nums,0,n-2);
        // int ans2=findmax(nums,1,n-1);
      
        // cases for in which we have to rob
        int ans1=nums[0]+findmax(nums,2,n-2,dp);
        int ans2=findmax(nums,1,n-1,dp);
        return max(ans1,ans2);
    }
    
};