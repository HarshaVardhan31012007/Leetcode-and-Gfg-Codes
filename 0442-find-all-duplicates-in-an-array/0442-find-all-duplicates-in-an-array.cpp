class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
           int idx=abs(nums[i]);
           if(nums[idx-1]>0)
           nums[idx-1]*=-1;
           else
           ans.push_back(idx);
        }
        return ans;
    }
};