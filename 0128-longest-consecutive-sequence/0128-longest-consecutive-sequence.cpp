class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // unordered_map<int,int>mpp;
        // int ans=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     int c=1;
        //     int k=nums[i];
        //     while(mpp.count(k-1)){
        //         c++;k--;
        //     }
        //     k=nums[i];
        //     while(mpp.count(k+1)){
        //         c++;k++;
        //     }
        //     ans=max(ans,c);
        //     mpp[nums[i]]=i;
        // }
        // return ans==INT_MIN?0:ans;


        sort(nums.begin(),nums.end());
        if(nums.size()==0) return 0;
        int c=1;
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) continue;
            if(nums[i]==(nums[i-1]+1)){
                c++;
            }
            else{
                ans=max(ans,c);
                c=1;
            }
        }
        ans=max(ans,c);
        return ans;
    }
};