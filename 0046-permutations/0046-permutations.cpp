class Solution {
public:
    // void solve(vector<int>&nums,int i,vector<vector<int>>&ans){
    //     if(i==nums.size()){
    //         ans.push_back(nums);
    //         return;
    //     }
    //     for(int j=i;j<nums.size();j++){
    //         swap(nums[i],nums[j]);
    //         solve(nums,i+1,ans);
    //         swap(nums[i],nums[j]);
    //     }
    //}
    // vector<vector<int>> permute(vector<int>& nums) {
    //     // vector<vector<int>>ans;
    //     // solve(nums,0,ans);
    //     // return ans;

    //     vector<vector<int>>ans;
    //     sort(nums.begin(),nums.end());
    //     ans.push_back(nums);
    //     while(next_permutation(nums.begin(),nums.end())){
    //        ans.push_back(nums);
    //     }
    //     return ans;
    // }


     void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp,int i){
        if(i==temp.size()){
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<temp.size();j++){
             if(temp[j]==INT_MAX){
                temp[j]=nums[i];
                solve(nums,ans,temp,i+1);
                temp[j]=INT_MAX;
             }
        }
     }
     vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp(nums.size(),INT_MAX);
        solve(nums,ans,temp,0);
        return ans;
    }
};