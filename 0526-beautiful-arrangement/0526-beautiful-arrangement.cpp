class Solution {
public:
    int solve(vector<int>&nums,int n,int i){
        if(i==n) {
            for(int i=0;i<nums.size();i++)
            cout<<nums[i];
            cout<<endl;
            return 1;
        }
        int ans=0;
        for(int j=i;j<n;j++){
            if(nums[j]%(i+1)==0||(i+1)%nums[j]==0){
                swap(nums[i],nums[j]);
                ans+=solve(nums,n,i+1);
                swap(nums[i],nums[j]);
            }
        }
        return ans;
    }
    int countArrangement(int n) {
       vector<int>nums(n);
       for(int i=0;i<n;i++){
        nums[i]=i+1;
       }
       return solve(nums,n,0);
    }
};