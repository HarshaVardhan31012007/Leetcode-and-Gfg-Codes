class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size();){
               // if(j>i+1&&nums[j]==nums[j-1]) continue;//1
                int p=j+1;int q=nums.size()-1;
                while(p<q){
                long long sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[p]+(long long)nums[q];
                if(sum==target){
                ans.push_back({nums[i],nums[j],nums[p++],nums[q--]});
                //optimization//need//
                while(p<q&&nums[q]==nums[q+1]) q--;
                }
                else if(sum<target)
                p++;
                else
                q--;
                //optimization//no need//
                // while(p<q&&q+1<nums.size()&&nums[q]==nums[q+1]) q--;
                // while(p<q&&p>j+1&&nums[p]==nums[p-1]) p++;
                }
                 //instead of 1 this also correct
                j++;
                while(j<nums.size()&&nums[j]==nums[j-1]) j++;
            }
        }
        return ans;
    }
};