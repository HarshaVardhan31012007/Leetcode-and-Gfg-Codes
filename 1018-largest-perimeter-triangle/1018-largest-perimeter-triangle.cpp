class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int maxi=INT_MIN;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int k=2;k<=n-1;k++){
            int j=k-1;
            int i=0;
            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                    maxi=max(maxi,nums[j-1]+nums[j]+nums[k]);
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        return maxi==INT_MIN?0:maxi;
    }
};