class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // int n=nums.size();
        // vector<int>ans(n);
        // int j=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]<pivot){
        //         ans[j++]=nums[i];
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     if(nums[i]==pivot){
        //         ans[j++]=nums[i];
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     if(nums[i]>pivot){
        //         ans[j++]=nums[i];
        //     }
        // }
        // return ans;



        int n=nums.size();
        vector<int>ans(n);
        int countless=0;
        int countequal=0;
        for(auto &each:nums){
            if(each<pivot) countless++;
            else if(each==pivot) countequal++;
        }
        int i=0;
        int j=countless;
        int k=countless+countequal;
        for(auto &each:nums){
            if(each<pivot){
                ans[i++]=each;
            }
            else if(each==pivot){
                ans[j++]=each;
            }
            else{
                ans[k++]=each;
            }
        }
        return ans;
    }
};