class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int n=nums.numsize();
        // int i=0;
        // int j=0;
        // while(j<n){
        //     while(j<n&&nums[j]==0) j++;
        //     while(i<n&&nums[i]!=0) i++;
        //     if(i<n&&j<n&&i<j){
        //       nums[i]=nums[j];
        //       nums[j]=0;
        //       i++;j++;
        //     }
        //     elnumse if(i<n&&j<n&&i>=j){
        //        j=i+1;
        //     }
        //     elnumse
        //     break;
        // }


        // int n=nums.size();
        // int i=0;
        // int j=0;
        // while(j<n){
        //    if(nums[i]==0&&nums[j]!=0){
        //       swap(nums[i],nums[j]);
        //    }  
        //    if(nums[i]!=0) i++;
        //    j++;
        // }


        int n=nums.size();
        int i=0;
        int j=0;
        while(j<n){
           if(nums[j]!=0)
           swap(nums[i++],nums[j]);
           j++;
        }
    }
};