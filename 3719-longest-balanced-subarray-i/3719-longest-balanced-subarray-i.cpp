class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            unordered_set<int>st;
            int o=0;int e=0;
            for(int j=i;j<nums.size();j++){
                if(!st.count(nums[j])){
                   st.insert(nums[j]);
                   if(nums[j]&1) o++;
                   else e++;
                }
                if(o==e)
                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};