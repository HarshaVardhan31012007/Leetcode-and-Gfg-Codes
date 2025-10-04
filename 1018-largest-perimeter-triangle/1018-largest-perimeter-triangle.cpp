class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int maxi=INT_MIN;
        sort(nums.begin(),nums.end());
        int n=nums.size();
            int k=n-1;
            int j=n-2;
            int i=n-3;
            while(i>=0){
                if(nums[i]+nums[j]>nums[k]){
                   return nums[i]+nums[j]+nums[k];
                }
                else{
                  k--;
                  j--;
                  i--;
                }
            }
        return 0;
    }
};