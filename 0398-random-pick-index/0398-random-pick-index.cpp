class Solution {
public:
    unordered_map<int,vector<int>>mpp;
    Solution(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int size=mpp[target].size();
        int idx=rand()%size;
        return mpp[target][idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */