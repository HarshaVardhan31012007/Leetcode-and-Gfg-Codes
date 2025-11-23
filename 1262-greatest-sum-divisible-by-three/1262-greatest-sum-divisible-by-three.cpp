class Solution {
public:
    bool check(vector<int>&nums,int i,int t){
        if(i>=nums.size()){
            if(t==0)
            return true;
            return false;
        }
        bool l=false;
        if(t>=nums[i])
        l=check(nums,i+1,t-nums[i]);
        bool e=check(nums,i+1,t);
        return l||e;
    }
    int maxSumDivThree(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int rem=sum%3;
        if(rem==0) return sum;
        while(rem<=sum){
            if(check(nums,0,rem))
              return sum-rem;
            rem+=3;
        }
        return 0;
    }
};