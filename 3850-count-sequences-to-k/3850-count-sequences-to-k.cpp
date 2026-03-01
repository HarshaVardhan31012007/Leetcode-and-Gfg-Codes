class Solution {
public:
    map<pair<int,pair<long long,long long>>,int>mpp;
    int countWays(vector<int>&nums,int i,long long val,long long val1,long long k){
        if(i>=nums.size()){
            if(val%val1==0){
                val=val/val1;
                if(val==k) return 1;
            }
            return 0;
        }
        if(mpp.count({i,{val,val1}})) return mpp[{i,{val,val1}}];
        int ans=0;
        ans+=countWays(nums,i+1,val*nums[i],val1,k);
        ans+=countWays(nums,i+1,val,val1*nums[i],k);
        ans+=countWays(nums,i+1,val,val1,k);
        return mpp[{i,{val,val1}}]=ans;
    }
    int countSequences(vector<int>& nums, long long k) {
        return countWays(nums,0,1,1,k);
    }
};