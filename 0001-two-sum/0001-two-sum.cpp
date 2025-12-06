class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map<int,int>mpp;
        // int s=-1;int e=-1;
        // for(int i=0;i<nums.size();i++){
        //     if(mpp.find(target-nums[i])!=mpp.end()){
        //         s=mpp[target-nums[i]];
        //         e=i;
        //         break;
        //     }
        //     mpp[nums[i]]=i;
        // }
        // return {s,e};


        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        int s=-1;int e=-1;
        for(int i=0;i<nums.size();i++){
            int current=nums[i];
            int required=target-nums[i];
            if(mpp.count(required)==1){
                if(current==required&&mpp[current].size()==1)
                continue;
                if(current==required&&mpp[current].size()>1)
                return {mpp[current][0],mpp[current][1]};
                else
                return {mpp[required][0],i};
            }
        }
        return {-1,-1};
    }
};