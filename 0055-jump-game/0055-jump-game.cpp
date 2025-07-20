class Solution {
public:
// bool solve(vector<int>&nums,int i,vector<int>&dp){
//   if(i==nums.size()-1) return true;
//   if(i>=nums.size()) return false;
//   if(dp[i]!=-1) return dp[i];//noneed of nums[i]==0 return false//loop takes 
//   //care of it
//   bool ans=false;
//   for(int jump=1;jump<=nums[i];jump++){
//    ans=ans||solve(nums,i+jump,dp);
//   }
//   return dp[i]=ans;
// }
// bool canJump(vector<int>& nums) {
//     vector<int>dp(nums.size()+1,-1);
//     return solve(nums,0,dp);
// }



bool solve(vector<int>&nums){
  vector<int>dp(nums.size()+1,0);
  dp[nums.size()-1]=1;
  for(int i=nums.size()-2;i>=0;i--){
  bool ans=false;
  for(int jump=1;jump<=nums[i];jump++){
    if(i+jump<nums.size())
   ans=ans||dp[i+jump];
  }
  dp[i]=ans;
  }
  return dp[0];
}
bool canJump(vector<int>& nums) {
    return solve(nums);
}


};