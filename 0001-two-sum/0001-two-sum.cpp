class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        int s=-1;int e=-1;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(target-nums[i])!=mpp.end()){
                s=mpp[target-nums[i]];
                e=i;
                break;
            }
            mpp[nums[i]]=i;
        }
        return {s,e};
    }
};