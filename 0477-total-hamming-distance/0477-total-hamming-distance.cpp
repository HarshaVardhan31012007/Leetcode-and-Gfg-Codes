class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        // int n=nums.size();
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int count=__builtin_popcount(nums[i]^nums[j]);
        //         ans+=count;
        //     }
        // }
        // return ans;


        int ans=0;
        for(int i=0;i<32;i++){
            int perBit=0;
            for(auto x:nums){
                perBit+=((x>>i)&1);
            }
            ans+=perBit*(nums.size()-perBit);
        }
        return ans;
    }
};