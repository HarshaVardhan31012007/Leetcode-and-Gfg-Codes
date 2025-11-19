class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        int s=0;
        int e=nums.size()-1;
        while(binary_search(begin(nums)+s,nums.begin()+e+1,original)){
            original=original*2;
        }
        return original;
    }
};