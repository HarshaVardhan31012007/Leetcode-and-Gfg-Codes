class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(i+1<nums.size()&&nums[i+1]<nums[i])
            count++;
        }
        if(count==0)
        return true;
        if(count==1)
        return nums[nums.size()-1]<=nums[0];
        return false;
    }
};