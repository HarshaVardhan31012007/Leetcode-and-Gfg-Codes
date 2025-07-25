class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp,int i,int f){     if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        if(f==-1||(!(nums[i]==nums[i-1]&&f==0))){
        temp.push_back(nums[i]);
        solve(nums,ans,temp,i+1,1);
        temp.pop_back();
        }
        solve(nums,ans,temp,i+1,0);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(nums,ans,temp,0,-1);
        return ans;
    }
};