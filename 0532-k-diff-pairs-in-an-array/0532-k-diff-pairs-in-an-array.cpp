class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       unordered_map<int,int>mpp;int ans=0;
       for(int i=0;i<nums.size();i++){
        int t=nums[i]-k;
        if((mpp.count(nums[i])==0||k==0)&&mpp.find(t)!=mpp.end()){
            if(k==0){
                if(mpp[t]==1)
                ans++;
            }
            else
            ans++;
        }
        mpp[nums[i]]++;
       } 
       return ans;
    }
};