class Solution {
public:
    int maximumLength(vector<int>& nums) {
        long long n=nums.size();
        unordered_map<long long,long long>mpp;
        for(auto &each:nums){
           mpp[each]++;
        }
        long long ans=0;
        for(long long i=0;i<n;i++){
            long long x=nums[i];
            if(x==1){
                continue;
            }
            long long p=0;
            while(1){
                if(!mpp.count(x)){
                    p--;
                    break;
                }
                if(mpp.count(x)&&mpp[x]==1) break;
                x=x*x;
                p++;
            }
            ans=max(ans,2*p+1);
        }
        if(mpp[1]&1) ans=max(ans,mpp[1]);
        else ans=max(ans,mpp[1]-1);
        return ans;
    }
};