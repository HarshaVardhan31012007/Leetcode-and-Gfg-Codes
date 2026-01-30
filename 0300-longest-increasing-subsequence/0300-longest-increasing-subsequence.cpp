class Solution {
public:
   // int lengthOfLIS(vector<int>& nums) {
        // int ans=1;
        // vector<int>dp(nums.size(),1);
        // for(int i=0;i<nums.size();i++){
        //    for(int j=0;j<i;j++){
        //         if(nums[j]<nums[i]){
        //             dp[i]=max(dp[i],dp[j]+1);
        //         }
        //    }
        //    ans=max(ans,dp[i]);
        // }
        // return ans;

        // int ans=1;
        // int ansIndex=0;
        // vector<int>dp(nums.size(),1);
        // vector<int>parent(nums.size(),-1);
        // for(int i=0;i<nums.size();i++){
        //    for(int j=0;j<i;j++){
        //         if(nums[j]<nums[i]&&dp[i]<dp[j]+1){
        //             dp[i]=dp[j]+1;
        //             parent[i]=j;
        //         }
        //    }
        //    if(dp[i]>ans){
        //      ans=dp[i];
        //      ansIndex=i;
        //    }
        // }
        // vector<int>prin;
        // while(parent[ansIndex]!=-1){
        //    prin.push_back(nums[ansIndex]);
        //    ansIndex=parent[ansIndex];
        // }
        // prin.push_back(nums[ansIndex]);
        // reverse(prin.begin(),prin.end());
        // for(auto &each:prin)
        // cout<<each<<" ";
        // cout<<endl;
        // return ans;

        // vector<int>ans;
        // for(int i=0;i<nums.size();i++){
        //     if(ans.empty()||ans.back()<nums[i])
        //     ans.push_back(nums[i]);
        //     else{
        //         auto it=lower_bound(ans.begin(),ans.end(),nums[i]);//it is lower bound not upperbound dry run this 4 10 4 3 8 9
        //         if(it!=ans.end())
        //         ans[it-ans.begin()]=nums[i];
        //     }
        // }
        // return ans.size();
   // }


      //int findSubsequences(int n,vector<int>&nums){
    //      vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //      for(int j=0;j<n+1;j++){
    //         dp[n][j]=0;
    //      }
    //     for(int curr=n-1;curr>=0;curr--){
    //       for(int prev=curr-1;prev>=-1;prev--){
    //         int l=0;
    //         if(prev==-1||nums[prev]<nums[curr])
    //         l=1+dp[curr+1][curr+1];
    //         int r=dp[curr+1][prev+1];
    //         dp[curr][prev+1]=max(l,r);
    //       }
    //     }
    //     return dp[0][0];
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     return findSubsequences(n,nums);
    // }



    int findSubsequences(int n,vector<int>&nums){
         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
         for(int j=0;j<n+1;j++){
            dp[n][j]=0;
         }
        for(int curr=n-1;curr>=0;curr--){
          for(int prev=curr-1;prev>=-1;prev--){
            int l=0;
            if(prev==-1||nums[prev]<nums[curr])
            l=1+dp[curr+1][curr+1];
            int r=dp[curr+1][prev+1];
            dp[curr][prev+1]=max(l,r);
          }
        }
        int i=0;
        int prev=-1;
        while(i<n){
            int maxi=INT_MIN;int temp=prev;
            if(dp[i+1][prev+1]>maxi){
                maxi=dp[i+1][prev+1];
            }
            if((prev==-1||nums[prev]<nums[i])&&1+dp[i+1][i+1]>maxi){
                maxi=dp[i+1][i+1];
                prev=i;
            }
            if(temp!=prev)
            cout<<nums[prev]<<endl;
            i++;
        }
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return findSubsequences(n,nums);
    }
};