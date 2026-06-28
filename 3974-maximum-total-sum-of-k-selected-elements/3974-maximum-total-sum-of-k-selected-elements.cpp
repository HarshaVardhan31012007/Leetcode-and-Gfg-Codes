class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(),nums.rend());
        int n=nums.size();
        long long res=0;
        for(int i=0;i<k;i++){
            res+=(1LL*nums[i]*max(mul,1));
            mul--;
        }
        return res;
    }
};