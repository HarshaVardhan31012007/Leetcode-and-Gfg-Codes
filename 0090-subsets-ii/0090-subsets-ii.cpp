class Solution {
public:
 void solve(vector<int>& nums,vector<vector<int>>&ans,vector<int>&output,int i){
        if(i==nums.size()){
            ans.push_back(output);
            return;
        }
        output.push_back(nums[i]);
       solve(nums,ans,output,i+1);
       output.pop_back();
       //to avoid duplicates
       int idx=i+1;
       while(idx<nums.size()&&nums[idx]==nums[idx-1])
       idx++;
       solve(nums,ans,output,idx);
    }
   
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         int i=0;
        vector<vector<int>>ans;
        vector<int>output;
        //sort important
        sort(nums.begin(),nums.end());
        solve(nums,ans,output,i);
        return ans;
    }
};