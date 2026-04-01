class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n,INT_MAX);
        arr[0]=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(j+nums[j]>=i&&arr[j]!=INT_MAX)
                arr[i]=min(arr[i],1+arr[j]);
            }
        }
        return arr[n-1]!=INT_MAX;
    }
};