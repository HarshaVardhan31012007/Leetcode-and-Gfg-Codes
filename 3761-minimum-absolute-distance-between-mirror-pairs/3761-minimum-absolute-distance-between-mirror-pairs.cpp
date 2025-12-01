class Solution {
public:
    int rever(int n){
        int num=0;
        while(n){
            num=num*10+(n%10);
            n=n/10;
        }
        return num;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(mpp.count(nums[i])){
                  ans=min(ans,i-mpp[nums[i]]);
            }
            mpp[rever(nums[i])]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};