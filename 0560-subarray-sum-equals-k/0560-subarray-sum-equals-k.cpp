class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       vector<int>prefix(nums.size(),0);
       prefix[0]=nums[0];
       for(int i=1;i<nums.size();i++){
        prefix[i]=nums[i]+prefix[i-1];
       } 
       unordered_map<int,int>mpp;
       int count=0;
       for(int i=0;i<nums.size();i++){
        if(prefix[i]==k)
        count++;
        int sum=prefix[i]-k;
        if(mpp.find(sum)!=mpp.end())
        count+=mpp[sum];
        mpp[prefix[i]]++;
       }
       return count;
    }
};