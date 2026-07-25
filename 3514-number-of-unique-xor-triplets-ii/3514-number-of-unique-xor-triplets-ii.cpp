class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int max_xor=2048;
        vector<int>pair_xor(max_xor,0);
        vector<int>triple_xor(max_xor,0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                pair_xor[nums[i]^nums[j]]=1;
            }
        }
        int ans=0;
        for(int xr=0;xr<max_xor;xr++){
             for(auto &each:nums){
                if(!pair_xor[xr^each]) continue;
                ans++;
                break;
             }
        }
        return ans;
    }
};