class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int i=0;int j=n-1;
        vector<int>ans(n);
        int idx=n-1;
        while(i<=j){
            if(nums[i]*nums[i]<nums[j]*nums[j]){
                ans[idx--]=nums[j]*nums[j];
                j--;
            }
            else{
                ans[idx--]=nums[i]*nums[i];
                i++;
            }
        }
        return ans;
    }
};