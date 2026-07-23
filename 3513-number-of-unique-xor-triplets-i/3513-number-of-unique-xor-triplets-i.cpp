class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int x=0;
        for(auto &each:nums){
            x=x|each;
        }
        if(nums.size()<=2) return nums.size();
        return x+1;
    }
};