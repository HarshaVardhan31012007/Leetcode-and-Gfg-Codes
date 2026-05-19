class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(),nums.end());

        int n=nums.size();
        if(n==1) return;
        int i=n-2;
        while(i>=0){
            if(nums[i]<nums[i+1]){
                break;
            }
            i--;
        }
        if(i<0){
            reverse(nums.begin(),nums.end());
            return;
        }
        int j=i+1;
        while(j<n){
            if(nums[j]>nums[i]){
                j++;
            }
            else
            break;
        }
        j--;
        swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
    }
};