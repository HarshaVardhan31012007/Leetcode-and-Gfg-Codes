class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                int p=j+1;int q=nums.size()-1;
                while(p<q){
                long long sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[p]+(long long)nums[q];
                if(sum==target)
                ans.push_back({nums[i],nums[j],nums[p++],nums[q--]});
                else if(sum<target)
                p++;
                else
                q--;
                while(q+1<nums.size()&&q>=0&&nums[q]==nums[q+1]) q--;
                }
            }
        }
        return ans;
    }
};