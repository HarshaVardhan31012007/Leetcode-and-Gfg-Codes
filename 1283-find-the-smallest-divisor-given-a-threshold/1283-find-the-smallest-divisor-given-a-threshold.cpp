class Solution {
public:
    bool possible(vector<int>&nums,int mid,int threshold){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil(nums[i]/(double)mid);
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1;
        int e=*max_element(nums.begin(),nums.end());
        int ans;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(nums,mid,threshold)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};