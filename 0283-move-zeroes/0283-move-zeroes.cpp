class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int i=0;
        // for(int j=0;j<nums.size();j++){
        //     if(nums[j]!=0)
        //     nums[i++]=nums[j];
        // }
        // fill(nums.begin()+i,nums.end(),0);

        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=0)
            swap(nums[i++],nums[j]);
        }
    }
};