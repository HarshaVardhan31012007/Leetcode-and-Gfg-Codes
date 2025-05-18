class Solution {
public:
    // int lengthOfLIS(vector<int>&nums,int s,int e){
    //     vector<int>ans;
    //     if(s<=e)
    //     ans.push_back(nums[s]);
    //     for(int i=s+1;i<=e;i++){
    //         if(ans.back()<nums[i])
    //         ans.push_back(nums[i]);
    //         else{
    //             auto it=lower_bound(ans.begin(),ans.end(),nums[i]);
    //             int idx=it-ans.begin();
    //             ans[idx]=nums[i];
    //         }
    //     }
    //     return ans.size();
    // }

    // int lengthOfLIS1(vector<int>&nums,int s,int e){
    //     vector<int>ans;
    //     if(s<=e)
    //     ans.push_back(nums[e]);
    //     for(int i=e-1;i>=s;i--){
    //         if(ans.back()<nums[i])
    //         ans.push_back(nums[i]);
    //         else{
    //             auto it=lower_bound(ans.begin(),ans.end(),nums[i]);
    //             int idx=it-ans.begin();
    //              ans[idx]=nums[i];
    //         }
    //     }
    //     return ans.size();
    // }
    // int solve(vector<int>&nums){
    //      int ans=INT_MAX;
    //      for(int i=1;i<nums.size()-1;i++){
    //         int a=lengthOfLIS(nums,0,i);int b=lengthOfLIS1(nums,i,nums.size()-1);
    //         int c=nums.size()+1-a-b;
    //         if(a>1&&b>1) 
    //         ans=min(ans,c);
    //      }
    //      return ans;
    // }
    // int minimumMountainRemovals(vector<int>& nums) {
    //     return solve(nums);
    // }



     void solve(vector<int>&nums,vector<int>&arr){
         vector<int>ans;
         ans.push_back(nums[0]);
         arr.push_back(1);
         for(int i=1;i<nums.size();i++){
              if(ans.back()<nums[i]){
                ans.push_back(nums[i]);
                arr.push_back(ans.size());
              }
              else{
                auto it=lower_bound(ans.begin(),ans.end(),nums[i]);
                int idx=it-ans.begin();
                ans[idx]=nums[i];
                arr.push_back(idx+1);
              }
         }
     }
     int minimumMountainRemovals(vector<int>& nums) {
        vector<int>lis,lds;int n=nums.size();
        solve(nums,lis);
        reverse(nums.begin(),nums.end());
        solve(nums,lds);
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(lis[i]==1||lds[n-i-1]==1) continue;
            ans=max(ans,lis[i]+lds[n-i-1]-1);
        }
        return n-ans;
     }
};