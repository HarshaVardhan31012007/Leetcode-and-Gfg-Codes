class Solution {
public:
    bool check(vector<int>& nums) {
        // int n=nums.size();
        // int i=1;
        // while(i<n){
        //     if(nums[i]>=nums[i-1]){
        //         i++;
        //     }
        //     else
        //     break;
        // }
        // if(i==n) return true;
        // i++;
        // while(i<n){
        //     if(nums[i]>=nums[i-1]){
        //         i++;
        //     }
        //     else
        //     break;
        // }
        // if(i==n){
        //     return nums[0]>=nums[n-1];
        // }
        // return false;



        int n=nums.size();
        int c=0;
        for(int i=1;i<n;i++){
            if(nums[i]>=nums[i-1]){
                c++;
            }
        }
        if(c==(n-1)) return true;
        if(c==(n-2)) return nums[0]>=nums[n-1];
        return false;
    }
};