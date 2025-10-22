class Solution {
public:
    int solve(vector<int>&nums,vector<vector<int>>& queries,int k){
           vector<int>diff(nums.size(),0);
           for(int i=0;i<=k;i++){
               diff[queries[i][0]]-=queries[i][2];
               if(queries[i][1]+1<nums.size())
               diff[queries[i][1]+1]+=queries[i][2];
           }
           long long int cumSum=0;
           for(int i=0;i<nums.size();i++){
               cumSum+=diff[i];
               if(cumSum+nums[i]>0)
               return false;
           }
           return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>v(n,0);
        // long long int sum=accumulate(nums.begin(),nums.end(),0);
        // if(sum==0) return 0;//overflow
        auto lambda=[](int x){
            return x==0;
        };
        if(all_of(begin(nums),end(nums),lambda))
        return 0;
        int l=0;
        int r=queries.size()-1;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(solve(nums,queries,mid)){
                ans=mid+1;
                r=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
};