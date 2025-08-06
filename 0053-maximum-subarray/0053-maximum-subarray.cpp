class Solution {
public:
    int func(vector<int>&nums,int s,int mid,int e){
        int sum=0;int maxi1=INT_MIN;
        for(int i=mid;i>=s;i--){
            sum+=nums[i];
            maxi1=max(maxi1,sum);
        }
        sum=0;int maxi2=INT_MIN;
        for(int j=mid+1;j<=e;j++){
           sum+=nums[j];
           maxi2=max(maxi2,sum);
        }
        return maxi1+maxi2;
    }
    int solve(vector<int>&nums,int s,int e){
        if(s==e){
            return nums[s];
        }
        int mid=s+(e-s)/2;
        int l=solve(nums,s,mid);
        int r=solve(nums,mid+1,e);
        int curr=func(nums,s,mid,e);
        return max(curr,max(l,r));
    }
    int maxSubArray(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};