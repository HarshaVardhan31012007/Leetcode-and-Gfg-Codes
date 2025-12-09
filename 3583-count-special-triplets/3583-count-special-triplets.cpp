class Solution {
public:
    // const int mod=1e9+7;
    // int specialTriplets(vector<int>& nums) {
    //     long long n=nums.size();
    //     vector<long long>prefix(n,0);
    //     unordered_map<long long,long long>mpp;
    //     mpp[nums[0]]=1;
    //     for(long long i=1;i<n;i++){
    //         auto it=mpp.find(nums[i]*2);
    //         if(it!=mpp.end())
    //         prefix[i]=(it->second)%mod;
    //         mpp[nums[i]]++;
    //     }
    //     vector<long long>suffix(n,0);
    //     unordered_map<long long,long long>mpp1;
    //     mpp1[nums[n-1]]=1;
    //     for(long long i=n-2;i>=0;i--){
    //         auto it=mpp1.find(nums[i]*2);
    //         if(it!=mpp1.end())
    //         suffix[i]=(it->second)%mod;
    //         mpp1[nums[i]]++;
    //     }
    //     long long ans=0;
    //     for(long long i=0;i<n;i++){
    //         ans=(ans+(prefix[i]%mod*suffix[i]%mod)%mod)%mod;
    //     }
    //     return ans%mod;
    // }





    // const int mod=1e9+7;
    // int specialTriplets(vector<int>& nums) {
    //     long long n=nums.size();
    //     vector<long long>prefix(n,0);
    //     unordered_map<long long,long long>mpp;
    //     mpp[nums[0]]=1;
    //     for(long long i=1;i<n;i++){
    //         auto it=mpp.find(nums[i]*2);
    //         if(it!=mpp.end())
    //         prefix[i]=(it->second)%mod;
    //         mpp[nums[i]]++;
    //     }
    //     vector<long long>suffix(n,0);
    //     unordered_map<long long,long long>mpp1;
    //     long long ans=0;
    //     mpp1[nums[n-1]]=1;
    //     for(long long i=n-2;i>=0;i--){
    //         auto it=mpp1.find(nums[i]*2);
    //         if(it!=mpp1.end())
    //         suffix[i]=(it->second)%mod;
    //         ans=(ans+(prefix[i]%mod*suffix[i]%mod)%mod)%mod;
    //         mpp1[nums[i]]++;
    //     }
    //     return ans%mod;
    // }




    const int mod=1e9+7;
    int specialTriplets(vector<int>& nums) {
        long long n=nums.size();
        vector<long long>prefix(n,0);
        unordered_map<long long,long long>mpp;
        mpp[nums[0]]=1;
        for(long long i=1;i<n;i++){
            auto it=mpp.find(nums[i]*2);
            if(it!=mpp.end())
            prefix[i]=(it->second)%mod;
            mpp[nums[i]]++;
        }
        unordered_map<long long,long long>mpp1;
        long long ans=0;
        mpp1[nums[n-1]]=1;
        for(long long i=n-2;i>=0;i--){
            auto it=mpp1.find(nums[i]*2);
            if(it!=mpp1.end()){
            long long suffix=(it->second)%mod;
            ans=(ans+(prefix[i]%mod*suffix%mod)%mod)%mod;
            }
            mpp1[nums[i]]++;
        }
        return ans%mod;
    }





    // const int mod=1e9+7;
    // int specialTriplets(vector<int>& nums) {
    //     long long n=nums.size();
    //     vector<long long>prefix(n,0);
    //     unordered_map<long long,long long>mpp;
    //     long long ans=0;
    //     mpp[nums[0]]=1;
    //     for(long long i=1;i<n;i++){
    //         auto it=mpp.find(nums[i]*2);
    //         if(it!=mpp.end())
    //         prefix[i]=(it->second)%mod;
    //          ans=(ans+(prefix[i]%mod*suffix%mod)%mod)%mod;
    //         mpp[nums[i]]++;
    //     }
    //     return ans%mod;
    //}
};