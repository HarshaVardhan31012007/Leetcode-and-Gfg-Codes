class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(maxi<i) return false;
            maxi=max(maxi,i+nums[i]);
        }
        return true;
    }
};