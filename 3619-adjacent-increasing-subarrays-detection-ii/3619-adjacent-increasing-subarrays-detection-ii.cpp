class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int p=0;
        int c=1;
        int ans=INT_MIN;
        for(int i=1;i<nums.size();i++){
             if(nums[i]>nums[i-1])
             c++;
             else{
                p=c;
                c=1;
             }
             ans=max(ans,c/2);
             ans=max(ans,min(c,p));
        }
        return ans;
    }
};