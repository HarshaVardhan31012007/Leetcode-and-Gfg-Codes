class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        // int one=0;
        // for(int i=0;i<k;i++){
        //     one+=nums[i];
        // }
        // int j=(int)nums.size()-1;int two=0;
        // while(k--){
        //     two+=nums[j];
        //     j--;
        // }
        // return two-one;


        // int one=0;int two=0;
        // for(int i=0,j=nums.size()-1;i<k;i++,j--){
        //    one+=nums[i];
        //    two+=nums[j];
        // }
        // return two-one;


         int one=0;int two=0;
        for(int i=0;i<k;i++){
           one+=nums[i];
           two+=nums[nums.size()-i-1];
        }
        return two-one;
    }
};