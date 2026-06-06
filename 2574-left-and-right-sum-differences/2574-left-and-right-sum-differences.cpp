class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int total=accumulate(nums.begin(),nums.end(),0);
        vector<int>ans;
        for(int i=0;i<n;i++){
           ans.push_back(abs(sum-(total-sum-nums[i])));
           sum+=nums[i];
        }
        return ans;
    }
};