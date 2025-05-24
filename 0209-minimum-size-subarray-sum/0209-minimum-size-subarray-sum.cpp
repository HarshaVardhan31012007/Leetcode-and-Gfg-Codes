class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s=0;
        int e=0;
        int len=INT_MAX;
        int sum=0;
        while(e<nums.size()){
            sum=sum+nums[e];
            while(sum>=target){
                len=min(len,e-s+1);
                sum=sum-nums[s];
                s++;
            }
            e++;
        }
        return len==INT_MAX?0:len;
    }
};