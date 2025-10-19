class Solution {
public:
    // int maxDistinctElements(vector<int>& nums, int k) {
    //     sort(nums.begin(),nums.end());
    //     unordered_map<int,int>mpp;
    //     for(int i=0;i<nums.size();i++){
    //         mpp[nums[i]]++;
    //     }
    //     int ans=0;
    //     for(int i=0;i<nums.size();i++){
    //         if(i>0&&nums[i]==nums[i-1]){
    //             for(int j=-k;j<=k;j++){
    //                 int newn=nums[i]+j;
    //                 if(!mpp.count(newn)){
    //                 mpp[newn]=1;
    //                 mpp[nums[i]]--;
    //                 ans++;
    //                 break;
    //                 }
    //             }
    //         }
    //         else
    //         ans++;
    //     }
    //     return ans;
    // }


    // int solve(vector<int>&nums,int k,int i,unordered_map<int,int>&mpp){
    //     if(i>=nums.size()) return 0;
    //     int l=0;
    //     if(i==0||nums[i]!=nums[i-1])
    //     l=1+solve(nums,k,i+1,mpp);
    //     int r=solve()
    // }
    int maxDistinctElements(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       int prev=INT_MIN;
       int count=0;
       for(int i=0;i<nums.size();i++){
            // if(prev<nums[i]-k){
            //     prev=nums[i]-k;
            //     count++;
            // }
            // else if(prev<nums[i]+k){
            //     prev=prev+1;
            //     count++;
            // }

            int temp=max(prev+1,nums[i]-k);
            if(temp<=nums[i]+k){
                prev=temp;
                count++;
            }
       }
       return count;
    }
};