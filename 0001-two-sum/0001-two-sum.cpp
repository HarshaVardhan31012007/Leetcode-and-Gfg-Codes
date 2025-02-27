class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map<int,int>mp;
        // for(int i=0;i<nums.size();i++){
        //     int req=target-nums[i];
        //     if(mp.find(req)!=mp.end()){
        //       return {i,mp[req]};
        //     }
        //     mp[nums[i]]=i;
        // } 
        // return {-1,-1};

         unordered_map<int,vector<int>>mp;

         for(int i=0;i<nums.size();i++)
         mp[nums[i]].push_back(i);

        for(int i=0;i<nums.size();i++){
            int req=target-nums[i];
            if(mp.find(req)!=mp.end()){
              if(req==nums[i]&&mp[req].size()==1)
              continue;
              if(req==nums[i]&&mp[req].size()>1)
              return {mp[req][0],mp[req][1]};
              return {i,mp[req][0]};
            }
        } 
        return {-1,-1};
    }
};