class Solution {
public:
    int minOperations(vector<int>& nums) {
        // unordered_map<int,pair<int,int>>mpp;
        // int idx=-1;
        // for(int i=0;i<nums.size();i++){
        //     if(!mpp.count(nums[i])){
        //         mpp[nums[i]]={-1,i};
        //     }
        //     else{
        //         mpp[nums[i]]={mpp[nums[i]].second,i};
        //         idx=max(idx,mpp[nums[i]].first);
        //     }
        // }
        // return ceil((idx+1)/3.0);


        unordered_map<int,int>mpp;
        int ans=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(mpp.count(nums[i])) break;
            mpp[nums[i]]++;
            ans++;
        }
        return ceil((nums.size()-ans)/3.0);
    }
};