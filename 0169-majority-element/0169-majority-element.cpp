class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int n=nums.size()/2;
        // for(int i=0;i<nums.size();i++){
        //     int count=1;
        //    for(int j=i+1;j<nums.size();j++){
        //      if(nums[i]==nums[j])
        //      count++;
        //    }
        //    if(count>n)
        //    return nums[i];
        // }
        // return -1;

        //method 2
        // int n=nums.size()/2;
        // sort(nums.begin(),nums.end());
        // if(nums.size()==1)
        // return nums[0];
        // int count=1;
        // for(int i=0;i<nums.size();i++){
        //     if(i+1<nums.size()&&nums[i]==nums[i+1]){
        //         count++;
        //         if(count>n)
        //         return nums[i];
        //     }
        //     else
        //     count=1;
        // }
        // return -1;

        // int n=nums.size()/2;
        // sort(nums.begin(),nums.end());;
        // int count=1;int ans=-1;
        // for(int i=0;i<nums.size();i++){
        //     if(i+1<nums.size()&&nums[i]==nums[i+1]){
        //         count++;
        //         if(count>n)
        //         return nums[i];
        //     }
        //     else{
        //     count=1;
        //     ans=nums[i];
        //     }
        // }
        // return ans;
        int freq=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(freq==0)
            ans=nums[i];
            if(ans==nums[i])
            freq++;
            else{
                freq--;
            }
        }
       return ans;
    }
};