class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int i=1;
        while(i<n){
            if(nums[i]>=nums[i-1]){
                i++;
            }
            else
            break;
        }
        if(i==n) return true;
        i++;
        while(i<n){
            if(nums[i]>=nums[i-1]){
                i++;
            }
            else
            break;
        }
        if(i==n){
            return nums[0]>=nums[n-1];
        }
        return false;
    }
};