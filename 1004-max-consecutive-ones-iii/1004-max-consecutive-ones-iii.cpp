class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // int n=nums.size();
        // int i=0;
        // int j=0;
        // int ans=0;
        // while(j<n){
        //    if(nums[j]==0){
        //       if(k>0)
        //       k--;
        //       else{
        //          while(nums[i]==1)i++;
        //          i++;
        //       }
        //    }
        //    if(i<=j)
        //    ans=max(ans,j-i+1);
        //    j++;
        // }
        // return ans;



        // int n=nums.size();
        // int i=0;
        // int j=0;
        // int ans=0;
        // while(j<n){
        //    if(nums[j]==0){
        //       k--;
        //    }
        //    if(k<0){
        //       if(nums[i]==0) k++;
        //       i++; 
        //    }
        //    if(i<=j&&k>=0)
        //    ans=max(ans,j-i+1);
        //    j++;
        // }
        // return ans;



        int n=nums.size();
        int i=0;
        int j=0;
        int zeros=0;
        int ans=0;
        while(j<n){
           if(nums[j]==0){
              zeros++;
           }
           if(zeros>k){
              if(nums[i]==0) zeros--;
              i++; 
           }
           if(zeros<=k)
           ans=max(ans,j-i+1);
           j++;
        }
        return ans;
    }
};