class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<pair<int,int>>v;
        // for(int i=0;i<nums.size();i++){
        //     v.push_back({nums[i],i});
        // }
        // sort(v.begin(),v.end());
        // int s=0;
        // int e=nums.size()-1;
        // while(s<e){
        //     int sum=v[s].first+v[e].first;
        //     if(sum==target){
        //         return {v[s].second,v[e].second};
        //     }
        //     else if(sum>target)
        //     e--;
        //     else if(sum<target)
        //     s++;
        // }
        // return {-1,-1};


        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            int t=target-nums[i];
            if(mpp.find(t)!=mpp.end()){
                return {mpp[t],i};
            }
            mpp[nums[i]]=i;
        }
        return {-1,-1};
    }
};