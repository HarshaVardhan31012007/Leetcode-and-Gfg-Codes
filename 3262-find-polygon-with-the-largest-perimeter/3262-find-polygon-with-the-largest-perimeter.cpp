class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<long long int>prefix(nums.size(),0);
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        for(int i=nums.size()-1;i>=2;i--){
             if(nums[i]<prefix[i-1])
             return prefix[i];
        }
        return -1;
    }
};