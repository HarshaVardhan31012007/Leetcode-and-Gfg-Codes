class Solution {
public:
    int findMax(vector<int>&nums,int s,int e){
        int next1=0;
        int next2=0;
        for(int i=e;i>=s;i--){
            int take=nums[i]+next2;
            int not_take=next1;
            int curr=max(take,not_take);
            next2=next1;
            next1=curr;
        }
        return next1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(findMax(nums,0,n-2),findMax(nums,1,n-1));
    }
};