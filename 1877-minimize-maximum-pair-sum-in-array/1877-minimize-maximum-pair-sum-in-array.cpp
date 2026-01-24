class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int maxi=INT_MIN;
        sort(nums.begin(),nums.end());
        for(int i=0,j=nums.size()-1;i<j;i++,j--){
            maxi=max(maxi,nums[i]+nums[j]);
        }
        return maxi;
    }
};