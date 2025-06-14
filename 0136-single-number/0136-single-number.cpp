class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int ans=0;
        // for(int i=0;i<nums.size();i++){
        //     ans=ans^nums[i];
        // }
        // return ans;


        // for(int i=0;i<nums.size();i++){
        //     int count=0;
        //     for(int j=0;j<nums.size();j++){
        //           if(nums[i]==nums[j])
        //           count++;
        //     }
        //     if(count&1)
        //     return nums[i];
        // }
        // return -1;



        // unordered_map<int,int>mpp;
        // for(auto &num:nums)
        // mpp[num]++;
        // for(auto &each:mpp){
        //     if(each.second&1)
        //     return each.first;
        // }
        // return -1;



        int i=0;
        int ans=-1;
        sort(nums.begin(),nums.end());
        while(i<nums.size()){
            if(i+1<nums.size()&&nums[i]==nums[i+1])
            i=i+2;
            else{
                ans=nums[i];
                break;
            }
        }
        return ans;
    }
};