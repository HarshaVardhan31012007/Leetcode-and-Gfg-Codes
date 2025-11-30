class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        vector<int>prefix(nums.size());
        prefix[0]=nums[0]%p;
        for(int i=1;i<nums.size();i++){
             prefix[i]=(prefix[i-1]+nums[i]%p)%p;
        }
        if(prefix[nums.size()-1]==0) return 0;
        vector<int>suffix(nums.size());
        suffix[nums.size()-1]=nums[nums.size()-1]%p;
        for(int i=nums.size()-2;i>=0;i--){
            suffix[i]=(suffix[i+1]+nums[i]%p)%p;
        }
        unordered_map<int,int>mpp;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(i==nums.size()-1){
                if(mpp.count(0)){
                    int idx=mpp[0];
                    ans=min(ans,i-idx);
                }
            }
            else{
                int a=suffix[i+1];
                if(a==0)
                ans=min(ans,i+1);
                int b=(p-a)%p;
                if(mpp.count(b)){
                   int idx=mpp[b];
                   ans=min(ans,i-idx);
                }
                mpp[prefix[i]]=i;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};