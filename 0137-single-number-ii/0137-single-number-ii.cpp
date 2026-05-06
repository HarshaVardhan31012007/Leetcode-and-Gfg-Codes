class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(j!=i&&nums[j]==nums[i])
                c++;
            }
            if(c==0) return nums[i];
        }
        return -1;
    }
};