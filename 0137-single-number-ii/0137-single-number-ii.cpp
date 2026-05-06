class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(auto &each:nums)
        mpp[each]++;
        for(auto &each:mpp){
            if(each.second==1) return each.first;
        }
        return -1;
    }
};