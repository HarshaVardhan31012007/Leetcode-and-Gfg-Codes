class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(s==e)
            return nums[s];
            int left=-1;
            if(mid-1>=0)
            left=nums[mid-1];
            int right=-1;
            if(mid+1<nums.size())
            right=nums[mid+1];
            int curr=nums[mid];
            if(curr==right){
                int idx=mid;
                if(idx&1)
                e=mid-1;
                else
                s=mid+1;
            }
            else if(curr==left){
                int idx=mid-1;
                if(idx&1)
                e=mid-1;
                else
                s=mid+1;
            }
            else
            return curr;
        }
        return -1;
    }
};