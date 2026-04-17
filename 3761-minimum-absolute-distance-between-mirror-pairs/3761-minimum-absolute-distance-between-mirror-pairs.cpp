class Solution {
public:
    int reversen(int n){
        int c=0;
        while(n){
            c=c*10+(n%10);
            n=n/10;
        }
        return c;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
             if(mpp.count(nums[i]))
             ans=min(ans,abs(i-mpp[nums[i]]));
             mpp[reversen(nums[i])]=i;
        }
        return (ans==INT_MAX)?-1:ans;
    }
    
};