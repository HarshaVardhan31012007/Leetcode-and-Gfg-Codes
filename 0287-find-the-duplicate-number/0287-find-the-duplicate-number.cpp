class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    //   for(int i=0;i<nums.size();i++){
    //     for(int j=i+1;j<nums.size();j++){
    //         if(nums[i]==nums[j])
    //         return nums[i];
    //     }
    //   }
    //   return -1;

    // unordered_map<int,int>mpp;
    // for(auto &num:nums){
    //     mpp[num]++;
    //     if(mpp[num]>1)
    //     return num;
    // }
    // return -1;

    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        if(i>0&&nums[i]==nums[i-1])
        return nums[i];
    }
    return -1;

    // int i=0;
    // while(i<nums.size()){
    //     int idx=nums[i];
    //     if(nums[idx-1]!=nums[i])
    //     swap(nums[idx-1],nums[i]);
    //     else
    //     i++;
    // }
    //return nums.back();
    }
};