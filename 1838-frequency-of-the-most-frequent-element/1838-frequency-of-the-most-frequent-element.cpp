class Solution {
public:
    typedef long long ll;
    int find(vector<int>&nums,vector<ll>&prefix,ll n,ll i,int k){
        ll s=0;
        ll e=i;
        ll ans=1;
        while(s<=e){
            ll mid=s+(e-s)/2;
            ll sum=prefix[i]-(mid>0?prefix[mid-1]:0);
            ll operations=(i-mid+1)*nums[i]-sum;
            if(operations<=k){
                ans=(i-mid+1);
                e=mid-1;
            }
            else
            s=mid+1;
        }
        return ans;
    }
    int maxFrequency(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // ll operations=0;
        // ll ans=LLONG_MIN;
        // ll j=0;ll i=0;ll sum=nums[0];
        // while(j<nums.size()){
        //     while(j<nums.size()&&((nums[j]*(j-i+1)-sum)<=k)){
        //         ans=max(ans,j-i+1);
        //         j++;
        //         if(j<nums.size())  sum+=nums[j];
        //     }
        //     if(j<nums.size()){
        //         sum-=nums[i];
        //         i++;
        //     }
        // }
        // return ans;




        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // ll j=0;ll i=0;ll sum=0;
        // while(j<nums.size()){
        //    sum+=nums[j];
        //    if(((j-i+1)*nums[j]-sum)>k){
        //        sum-=nums[i];
        //        i++;
        //    }
        //    j++;
        // }
        // return nums.size()-i;


        vector<ll>prefix(nums.size(),0);
        sort(nums.begin(),nums.end());
        prefix[0]=nums[0];
        ll n=nums.size();
        for(ll i=1;i<n;i++){
             prefix[i]=prefix[i-1]+nums[i];
        }
        ll ans=1;
        for(ll i=0;i<n;i++){
            ll curr=find(nums,prefix,n,i,k);
            ans=max(ans,curr);
        }
        return ans;
    }
};