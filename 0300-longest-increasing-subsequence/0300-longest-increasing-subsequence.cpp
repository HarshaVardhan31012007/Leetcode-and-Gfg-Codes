class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
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


        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(ans.empty()||ans.back()<nums[i])
            ans.push_back(nums[i]);
            else{
                auto it=lower_bound(ans.begin(),ans.end(),nums[i]);//it is lower bound not upperbound dry run this 4 10 2 3 8 9
                if(it!=ans.end())
                ans[it-ans.begin()]=nums[i];
            }
        }
        return ans.size();
    }
};