// class Solution {
// public:
//     int solve(vector<int>&nums,int n,int i){
//         if(i==n) {
//             return 1;
//         }
//         int ans=0;
//         for(int j=i;j<n;j++){
//             if(nums[j]%(i+1)==0||(i+1)%nums[j]==0){
//                 swap(nums[i],nums[j]);
//                 ans+=solve(nums,n,i+1);
//                 swap(nums[i],nums[j]);
//             }
//         }
//         return ans;
//     }
//     int countArrangement(int n) {
//        vector<int>nums(n);
//        for(int i=0;i<n;i++){
//         nums[i]=i+1;
//        }
//        return solve(nums,n,0);
//     }
// };


class Solution {
public:
    int solve(vector<int>&nums,int n,int k){
        if(k==n+1) {
            return 1;
        }
        int ans=0;
        for(int j=1;j<=n;j++){
                if(nums[j]==0&&(j%k==0||k%j==0)){
                nums[j]=k;
                ans+=solve(nums,n,k+1);
                nums[j]=0;
                }
        }
        return ans;
    }
    int countArrangement(int n) {
       vector<int>nums(n+1);
       return solve(nums,n,1);
    }
};