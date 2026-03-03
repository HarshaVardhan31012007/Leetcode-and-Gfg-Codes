class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>freq;
        unordered_map<int,int>freq1;
        int distinct=0;int j=0;int i=0;int distinct1=0;int i1=0;
        int ans=0;
        while(j<n){
            freq[nums[j]]++;
            freq1[nums[j]]++;
            if(freq[nums[j]]==1) distinct++;
            if(freq1[nums[j]]==1) distinct1++;
            while(distinct>k){
                freq[nums[i]]--;
                if(freq[nums[i]]==0)
                distinct--;
                i++;
            }
            while(distinct1>=k){
                freq1[nums[i1]]--;
                if(freq1[nums[i1]]==0)
                distinct1--;
                i1++;
            }
            ans+=i1-i;
            j++;
        }
        return ans;
    }
};