class Solution {
public:
     // vector<int> minBitwiseArray(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int>ans(n,-1);
    //     for(int i=0;i<n;i++){
    //         int mask=nums[i];
    //         for(int sub=mask;sub>=1;sub--){
    //             if((sub|sub+1)==mask){
    //                 ans[i]=sub;
    //             }
    //         }
    //     }
    //     return ans;
    // }

    // vector<int> minBitwiseArray(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int>ans(n,-1);
    //     for(int i=0;i<n;i++){
    //         int mask=nums[i];
    //         for(int sub=mask;sub>=1;sub=(sub-1)&mask){
    //             if((sub|sub+1)==mask){
    //                 ans[i]=sub;
    //             }
    //         }
    //     }
    //     return ans;
    // }



    // vector<int> minBitwiseArray(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int>ans(n,-1);
    //     for(int i=0;i<n;i++){
    //         int mask=nums[i];
    //         if(!(mask&1)) continue;
    //         int zero=-1;
    //         while(mask&1){
    //            zero=zero<<1;
    //            mask=mask>>1;
    //         }
    //         zero=zero>>1;
    //         int val=(nums[i]&zero);
    //         ans[i]=val-1;
    //     }
    //     return ans;
    // }


     vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int mask=nums[i];
            if(!(mask&1)) {
               ans.push_back(-1);
               continue;
            }
            int mask1=1;
            while(mask&1){
               mask1=mask1<<1;
               mask=mask>>1;
            }
            mask1=mask1>>1;
            int val=(nums[i]&(~(mask1)));
            ans.push_back(val);
        }
        return ans;
    }
};