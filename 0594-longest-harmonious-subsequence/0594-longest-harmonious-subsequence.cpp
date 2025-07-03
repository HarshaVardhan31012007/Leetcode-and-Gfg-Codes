class Solution {
public:

   //recursion not correct

    //int findLHS(vector<int>& nums) {
    //    sort(nums.begin(),nums.end());
    //    int i=0;int ans=0;
    //    for(int j=0;j<nums.size();j++){
    //     while(nums[j]-nums[i]>1)
    //     i++;
    //     if(nums[j]-nums[i]==1)
    //     ans=max(ans,j-i+1);
    //    }
    //    return ans;
    //    }

    // int solve(vector<int>&nums,int i,int maxi,int mini){
    //     if(i>=nums.size()) return 0; 
    //     int l=0;
    //     int tmax=max(maxi,nums[i]);
    //     int tmin=min(nums[i],mini);
    //     if(abs(tmax-tmin)<=1)
    //     l=1+solve(nums,i+1,tmax,tmin);
    //     int r=solve(nums,i+1,maxi,mini);
    //     return max(l,r);
    // }
    // int findLHS(vector<int>& nums) {
    //   int ans=solve(nums,0,INT_MIN,INT_MAX);
    //   sort(nums.begin(),nums.end());
    //   int mini=INT_MAX;int maxi=INT_MIN;
    //   for(int i=0;i<nums.size()-1;i++){
    //     if(nums[i+1]-nums[i]<mini)
    //     mini=nums[i+1]-nums[i];
    //     if(nums[i+1]-nums[i]>maxi)
    //     maxi=nums[i+1]-nums[i];
    //   }
    //   if(mini>1) return 0;
    //   if(maxi<1) return 0;
    //   return ans;
    // }

    
    // int findLHS(vector<int>& nums) {
    //  sort(nums.begin(),nums.end());
    //    int i=0;int ans=0;
    //    for(int j=0;j<nums.size();j++){
    //     while(nums[j]-nums[i]>1)
    //     i++;
    //     if(nums[j]-nums[i]==1)
    //     ans=max(ans,j-i+1);
    //    }
    //    return ans;
    //  }


     int findLHS(vector<int>& nums) {
        unordered_map<int,int>mpp;int ans=0;
        for(int i=0;i<nums.size();i++)
        mpp[nums[i]]++;
        for(auto it:mpp){
            int num=it.first;
            auto it1=mpp.find(num+1);
            if(it1==mpp.end()) continue;
            ans=max(ans,it.second+it1->second);
        }
        return ans;
     }
};