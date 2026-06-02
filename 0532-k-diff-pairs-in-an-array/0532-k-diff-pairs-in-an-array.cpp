class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        int c=0;
        while(j<n){
            if((nums[j]-nums[i])==k){
                c++;
                i++;j++;
                while(j<n&&nums[j]==nums[j-1]) j++;
            }
            else if((nums[j]-nums[i])<k){
                j++;
            }
            else{
                i++;
            }
            if(i==j) j++;
        }
        return c;
    }
};