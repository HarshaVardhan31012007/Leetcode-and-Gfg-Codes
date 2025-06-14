class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int ans=0;
        // for(int i=0;i<nums.size();i++){
        //     ans=ans^nums[i];
        // }
        // return ans;

        unordered_map<int,int>mpp;
        for(auto &num:nums)
        mpp[num]++;
        for(auto &each:mpp){
            if(each.second&1)
            return each.first;
        }
        return -1;
    }
};