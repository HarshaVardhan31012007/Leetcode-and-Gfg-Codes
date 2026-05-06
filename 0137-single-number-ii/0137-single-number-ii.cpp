class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // for(int i=0;i<32;i++){
        //     for(auto &each:nums){

        //     }
        // }


        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(i+1<nums.size()&&nums[i]==nums[i+1]) continue;
            return nums[i];
        }
        return -1;
    }
};