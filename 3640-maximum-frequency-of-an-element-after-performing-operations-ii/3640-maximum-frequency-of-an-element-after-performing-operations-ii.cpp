class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        // int maxi=-1e9;
        // int mini=1e9;
        // for(auto &each:nums){
        //     maxi=max(maxi,each);
        //     mini=min(mini,each);
        // }
        // vector<int>v(maxi-mini+2,0);
        // cout<<v.size()<<endl;
        // for(auto &each:nums){
        //     v[each-mini+1]++;
        // }
        // for(int i=1;i<=maxi-mini+1;i++)
        // v[i]+=v[i-1];
        // int ans=1;
        // for(int curr=mini;curr<=maxi;curr++){
        //     int l=max(mini,curr-k);
        //     int r=min(maxi,curr+k);
        //     int f=v[curr-mini+1]-v[curr-1-mini+1];
        //     int extra=min(numOperations,v[r-mini+1]-v[l-1-mini+1]-f);
        //     ans=max(ans,f+extra);
        // }
        // return ans;




        map<int,int>mpp;
        int mini=1e9;
        int maxi=1;
        unordered_map<int,int>freq;
        for(auto &each:nums){
            maxi=max(maxi,each);
            mini=min(mini,each);
            freq[each]++;
        }
        for(int i=0;i<nums.size();i++){
            int l=max(nums[i]-k,mini);
            int r=min(nums[i]+k,maxi);
            mpp[l]+=1;
            mpp[nums[i]]+=0;
            if(r+1<=maxi)
            mpp[r+1]-=1;
        }
        int ans=1;
        int cumSum=0;
        for(auto it=mpp.begin();it!=mpp.end();it++){
            cumSum+=it->second;
            int f=freq[it->first];
            int extra=min(numOperations,cumSum-f);
            ans=max(ans,f+extra);
        }
        return ans;
    }
};