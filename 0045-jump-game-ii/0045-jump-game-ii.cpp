class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int ans=0;
        while(r<n-1){
            int farthest=INT_MIN;
            for(int k=l;k<=r;k++){
                farthest=max(farthest,k+nums[k]);
            }
            l=r+1;
            r=farthest;
            ans++;
        }
        return ans;
    }
};