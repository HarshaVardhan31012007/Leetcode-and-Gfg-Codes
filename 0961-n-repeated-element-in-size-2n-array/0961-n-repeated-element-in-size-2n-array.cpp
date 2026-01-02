class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // for(int i=1;i<nums.size();i++){
        //     if(i>0&&nums[i]==nums[i-1])
        //     return nums[i];
        // }
        // return -1;



        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            if(st.count(nums[i]))
            return nums[i];
            else
            st.insert(nums[i]);
        }
        return -1;
    }
};