class Solution {
public:
    int find(vector<int>&nums){
        int n=nums.size();
        int s=0;
        int e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(mid+1<n&&nums[mid]>nums[mid+1]) return mid;
            if(nums[s]<=nums[mid]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return n-1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int idx=find(nums);
        auto it=lower_bound(nums.begin(),nums.begin()+idx+1,target);
        if(it!=nums.begin()+idx+1&&(*it)==target) return it-nums.begin();
        it=lower_bound(nums.begin()+idx+1,nums.end(),target);
        if(it!=nums.end()&&(*it)==target) return it-nums.begin();
        return -1;
    }
};