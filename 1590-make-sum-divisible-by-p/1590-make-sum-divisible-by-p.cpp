class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        vector<int>suffix(nums.size());
        suffix[nums.size()-1]=nums[nums.size()-1]%p;
        for(int i=nums.size()-2;i>=0;i--){
            suffix[i]=(suffix[i+1]+nums[i]%p)%p;
        }
        if(suffix[0]==0) return 0;
        unordered_map<int,int>mpp;
        int ans=INT_MAX;int rem=0;//prefix remainder// as we are going from left to right prefix[i] can be calculated on moving each step forward so prefix reamiander array is not required 
        for(int i=0;i<nums.size();i++){
                rem=(rem+nums[i]%p)%p;
                int a=(i==nums.size()-1?0:suffix[i+1]);
                if(i!=nums.size()-1&&a==0)
                ans=min(ans,i+1);
                int b=(p-a)%p;
                if(mpp.count(b)){
                   int idx=mpp[b];
                   ans=min(ans,i-idx);
                }
                mpp[rem]=i;// go on updating as we required smallest
        }
        return ans==INT_MAX?-1:ans;



        //normaly if remainder is fixed we can use array for fast accessing 
        //but see constraint of p it is 10 power 9 so memory limit exceeded wil be there 
        //so all possible p's may not occur in nums so use map to save space



        // vector<int>suffix(nums.size());
        // suffix[nums.size()-1]=nums[nums.size()-1]%p;
        // for(int i=nums.size()-2;i>=0;i--){
        //     suffix[i]=(suffix[i+1]+nums[i]%p)%p;
        // }
        // if(suffix[0]==0) return 0;
        // //unordered_map<int,int>mpp;//in map we store remainder which has fixed number of possibilites so use array which is better than map for accessing
        // vector<int>v(p,-1);
        // int ans=INT_MAX;
        // int rem=0;//prefix remainder// as we are going from left to right prefix[i] can be calculated on moving each step forward so prefix reamiander array is not required 
        // for(int i=0;i<nums.size();i++){
        //         rem=(rem+nums[i]%p)%p;
        //         int a=(i==nums.size()-1?0:suffix[i+1]);
        //         if(i!=nums.size()-1&&a==0)
        //         ans=min(ans,i+1);
        //         int b=(p-a)%p;
        //         if(v[b]!=-1){
        //            int idx=v[b];
        //            ans=min(ans,i-idx);
        //         }
        //         v[rem]=i;// go on updating as we required smallest
        // }
        // return ans==INT_MAX?-1:ans;
    }
};