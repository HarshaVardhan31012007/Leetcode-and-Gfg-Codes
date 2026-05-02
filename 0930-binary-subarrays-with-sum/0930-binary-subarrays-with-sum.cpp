class Solution {
public:
    // int solve(vector<int>&nums,int t){
    //      int sum=0;
    //      int i=0;
    //      int j=0;
    //      int n=nums.size();
    //      int ans=0;
    //      while(j<n){
    //         sum+=nums[j];
    //         while(i<n&&sum>t){
    //            sum-=nums[i];
    //            i++;
    //         }
    //         if(i==n) break;
    //         if(i<=j)
    //         ans+=(j-i+1);
    //         j++;
    //      }
    //      return ans;
    // }
    // int numSubarraysWithSum(vector<int>& nums, int goal) {
    //     return solve(nums,goal)-solve(nums,goal-1);
    // }



    // int solve(vector<int>&nums,int t){
    //     if(t<0) return 0;
    //      int sum=0;
    //      int i=0;
    //      int j=0;
    //      int n=nums.size();
    //      int ans=0;
    //      while(j<n){
    //         sum+=nums[j];
    //         while(sum>t){
    //            sum-=nums[i];
    //            i++;
    //         }
    //         ans+=(j-i+1);
    //         j++;
    //      }
    //      return ans;
    // }
    // int numSubarraysWithSum(vector<int>& nums, int goal) {
    //     return solve(nums,goal)-solve(nums,goal-1);
    // }



    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
         int sum=0;
         int i=0;
         int j=0;
         int n=nums.size();
         int ans=0;
         while(j<n){
            sum+=nums[j];
            while(sum>goal){
               sum-=nums[i];
               i++;
            }
            if(sum==goal){
                int c=1;int start=i;
                while(i<n&&nums[i]==0){
                    c++;i++;
                }
                int c1=1;
                j++;
                while(j<n&&nums[j]==0){
                    j++;
                    c1++;
                }
                if(i<j)
                ans+=c*c1;
                else{
                    int len=j-start;
                    ans+=(len*(len+1))/2;
                }
            }
            else
            j++;
         }
         return ans;
    }
};