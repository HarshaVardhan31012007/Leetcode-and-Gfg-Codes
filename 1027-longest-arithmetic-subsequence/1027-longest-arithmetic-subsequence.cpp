class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<unordered_map<int,int>>dp(nums.size()+1);
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                int diff=nums[j]-nums[i];
                dp[i][diff]=((dp[j].count(diff))?dp[j][diff]+1:2);
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};