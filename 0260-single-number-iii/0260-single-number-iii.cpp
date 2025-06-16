class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // vector<int>ans;
        // for(int i=0;i<nums.size();i++){
        //     if((i==0||nums[i]!=nums[i-1])&&(i==nums.size()-1||nums[i]!=nums[i+1]))
        //     ans.push_back(nums[i]);
        // }
        // return ans;

      unordered_map<int,int>mpp;
      for(int i=0;i<nums.size();i++){
        mpp[nums[i]]++;
      }
      int ans1=-1;int ans2=-1;
      for(int i=0;i<nums.size();i++){
          if(mpp[nums[i]]==1&&(ans1!=nums[i]&&ans2!=nums[i])){
            if(ans1==-1)
            ans1=nums[i];
            else
            ans2=nums[i];
          }
      }
          return {ans1,ans2};
    }
};