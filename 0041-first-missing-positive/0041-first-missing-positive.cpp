class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=1;
        for(int j=0;j<nums.size();j++){
            if(nums[j]<=0||j>0&&nums[j]==nums[j-1]) continue;
            if(nums[j]==i)
            i++;
            else
            return i;
        }
        return i;
    }
};