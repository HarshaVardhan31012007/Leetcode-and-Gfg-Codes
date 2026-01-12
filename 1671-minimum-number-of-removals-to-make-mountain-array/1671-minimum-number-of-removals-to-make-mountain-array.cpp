class Solution {
public:
    // int minimumMountainRemovals(vector<int>& nums) {
    //      int n=nums.size();
    //      vector<int>dp1(n,1);vector<int>dp2(n,1);
    //      for(int i=0;i<n;i++){
    //         for(int j=0;j<i;j++){
    //             if(nums[i]>nums[j]&&dp1[i]<dp1[j]+1){
    //                 dp1[i]=dp1[j]+1;
    //             }
    //         }
    //      }
    //      for(int i=n-1;i>=0;i--){
    //         for(int j=i+1;j<n;j++){
    //             if(nums[i]>nums[j]&&dp2[i]<dp2[j]+1){
    //                 dp2[i]=dp2[j]+1;
    //             }
    //         }
    //      }
    //      int maxi=INT_MIN;
    //      for(int i=0;i<n;i++){
    //         if(dp1[i]>=2&&dp2[i]>=2)//[9,8,1,7,6,5,4,3,2,1] important to check arr length should be 3
    //         maxi=max(maxi,dp1[i]+dp2[i]-1);
    //      }
    //      return n-maxi;
    // }



    vector<int>findLis(vector<int>&nums,int n){
        vector<int>lis(n,1);
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            int idx=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            if(idx==temp.size()){
                temp.push_back(nums[i]);
            }
            else
            temp[idx]=nums[i];
            lis[i]=temp.size();
        }
        return lis;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>lis=findLis(nums,n);
        reverse(nums.begin(),nums.end());
        vector<int>lds=findLis(nums,n);
        reverse(lds.begin(),lds.end());
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(lis[i]>1&&lds[i]>1)
            maxi=max(maxi,lis[i]+lds[i]-1);
        }
        return n-maxi;
    }
};