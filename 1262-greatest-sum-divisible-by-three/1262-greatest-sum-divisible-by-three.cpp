class Solution {
public:
    bool check(vector<int>&nums,vector<int>&cumsum,int t){
         unordered_map<int,bool>mpp;
         for(int i=0;i<nums.size();i++){
            if(cumsum[i]==t) return true;
            if(mpp.count(cumsum[i]-t)) return true;
            mpp[cumsum[i]]=true;
         }
         return false;
    }
    bool check(vector<int>&nums,int i,int t){
        if(i>=nums.size()){
            if(t==0)
            return true;
            return false;
        }
        bool l=false;
        if(t>=nums[i])
        l=check(nums,i+1,t-nums[i]);
        bool e=check(nums,i+1,t);
        return l||e;
    }
    int maxSumDivThree(vector<int>& nums) {
        vector<int>cumsum(nums.size(),0);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            cumsum[i]=sum;
        }
        int rem=sum%3;
        if(rem==0) return sum;
        while(rem<=sum){
            // if(check(nums,cumsum,rem))
            //   return sum-rem;
            if(check(nums,0,rem))
              return sum-rem;
            rem+=3;
        }
        return 0;
    }
};