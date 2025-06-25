class Solution {
public:
    int findDuplicate(vector<int>& arr) {
    //   for(int i=0;i<nums.size();i++){
    //     for(int j=i+1;j<nums.size();j++){
    //         if(nums[i]==nums[j])
    //         return nums[i];
    //     }
    //   }
    //   return -1;

    // unordered_map<int,int>mpp;
    // for(auto &num:nums){
    //     mpp[num]++;
    //     if(mpp[num]>1)
    //     return num;
    // }
    // return -1;

    // sort(nums.begin(),nums.end());
    // for(int i=0;i<nums.size();i++){
    //     if(i>0&&nums[i]==nums[i-1])
    //     return nums[i];
    // }
    // return -1;


    // for(int i=0;i<nums.size();i++){
    //     int idx=abs(nums[i]);
    //     if(nums[idx-1]>0)
    //     nums[idx-1]*=-1;
    //     else
    //     return idx;
    // }
    // return -1;

    // int i=0;
    // while(i<nums.size()){
    //     int idx=nums[i];
    //     if(nums[idx-1]!=nums[i])
    //     swap(nums[idx-1],nums[i]);
    //     else
    //     i++;
    // }
    //return nums.back();



    //  int i=0;
    // while(i<nums.size()){
    //     int idx=nums[i];
    //     if(nums[idx]!=nums[i])
    //     swap(nums[idx],nums[i]);
    //     else
    //     i++;
    // }
    // return nums[0];


     //positioning method
     while(arr[arr[0]]!=arr[0]){
        swap(arr[arr[0]],arr[0]);
     }
     return arr[0];
    }
};