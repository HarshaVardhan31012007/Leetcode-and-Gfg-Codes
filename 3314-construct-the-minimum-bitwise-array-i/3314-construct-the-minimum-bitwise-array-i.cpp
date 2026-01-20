class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            int mask=nums[i];
            for(int sub=mask;sub>=1;sub--){
                if((sub|sub+1)==mask){
                    ans[i]=sub;
                }
            }
        }
        return ans;
    }

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
};