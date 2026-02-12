class Solution {
  public:
    vector<int>solve(vector<int>&nums,int n){
        vector<int>ans;
        vector<int>dp;
        for(int i=0;i<n;i++){
            if(ans.empty()||nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int idx=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[idx]=nums[i];
            }
            dp.push_back(ans.size());
        }
        return dp;
    }
    int longestBitonicSequence(int n, vector<int> &nums) {
        vector<int>dp1=solve(nums,n);
        reverse(nums.begin(),nums.end());
        vector<int>dp2=solve(nums,n);
        reverse(dp2.begin(),dp2.end());
        reverse(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp1[i]>1&&dp2[i]>1)
            ans=max(ans,dp1[i]+dp2[i]-1);
        }
        return ans;
    }
};
