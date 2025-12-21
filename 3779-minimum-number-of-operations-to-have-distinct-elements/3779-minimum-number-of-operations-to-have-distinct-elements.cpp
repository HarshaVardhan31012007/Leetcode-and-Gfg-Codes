class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,pair<int,int>>mpp;
        int idx=-1;
        for(int i=0;i<nums.size();i++){
            if(!mpp.count(nums[i])){
                mpp[nums[i]]={-1,i};
            }
            else{
                mpp[nums[i]]={mpp[nums[i]].second,i};
                idx=max(idx,mpp[nums[i]].first);
            }
        }
        return ceil((idx+1)/3.0);
    }
};