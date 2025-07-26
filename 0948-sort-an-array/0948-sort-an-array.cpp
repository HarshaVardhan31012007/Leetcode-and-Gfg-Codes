class Solution {
public:
    void mergeInPlace(vector<int>&nums,int s,int e){
        int gap=e-s+1;
        while(gap>0){
            int i=s;int j=i+gap;
            while(j<=e){
                if(nums[i]>nums[j]){
                    swap(nums[i],nums[j]);
                }
                i++;j++;
            }
            //if(gap==1) break;
            //gap=gap/2+gap%2;
            gap=gap<=1?0:gap/2+gap%2;
        }
    }
    void mergeSort(vector<int>&nums,int s,int e){
       if(s<e){
          int mid=s+(e-s)/2;
          mergeSort(nums,s,mid);
          mergeSort(nums,mid+1,e);
          mergeInPlace(nums,s,e);
       }
    }
    vector<int> sortArray(vector<int>& nums) {
       mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};