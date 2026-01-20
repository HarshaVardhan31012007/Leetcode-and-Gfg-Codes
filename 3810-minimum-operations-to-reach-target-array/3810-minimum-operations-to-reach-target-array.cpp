class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_set<int>st;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=target[i]){
                if(!st.count(nums[i])){
                    st.insert(nums[i]);
                    ans++;
                }
            }
        }
        return ans;
    }
};