class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int total=0;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            total+=nums[i];
            sum+=i*nums[i];
        }
        int last=n-1;
        int maxi=sum;
        for(int i=1;i<n;i++){
            sum-=(n-1)*nums[last];
            sum+=(total-nums[last]);
            last--;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};