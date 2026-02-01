class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans=INT_MAX;
        int mini=INT_MAX;
        for(int i=1;i<nums.size();i++){
           if(mini!=INT_MAX)
           ans=min(ans,nums[0]+nums[i]+mini);
           mini=min(mini,nums[i]);
        }
        return ans;
    }
};