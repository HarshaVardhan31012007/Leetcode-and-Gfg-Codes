class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        long long ans=0;
        int i=0;int j=0;
        int n=nums.size();
        unordered_map<int,int>freq;
        unordered_map<int,int>freq1;
        int distinct=0;int atleastm=0;int i1=0;
        while(j<n){
            freq[nums[j]]++;
            if(freq[nums[j]]==1) distinct++;
            while(distinct>k){
                freq[nums[i]]--;
                if(freq[nums[i]]==0)
                distinct--;
                i++;
            }
            freq1[nums[j]]++;
            if(freq1[nums[j]]==m) atleastm++;
            while(atleastm>=k){
                if(freq1[nums[i1]]==m)
                atleastm--;
                freq1[nums[i1]]--;
                i1++;
            }
            if(i1>i)
            ans+=i1-i;
            j++;
        }
        return ans;
    }
};