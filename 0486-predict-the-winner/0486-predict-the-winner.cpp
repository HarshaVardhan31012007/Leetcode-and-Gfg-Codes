class Solution {
public:
    int solve(vector<int>&nums,int s,int e){
      if(s>e) return 0;
      int ans=INT_MIN;
      ans=max(ans,max(nums[s]-solve(nums,s+1,e),nums[e]-solve(nums,s,e-1)));
      return ans;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        if(n%2==0) return true;
        int ans=solve(nums,0,n-1);
        return ans>=0;
    }
};