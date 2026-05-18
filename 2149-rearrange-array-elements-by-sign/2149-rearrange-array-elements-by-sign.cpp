class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int i=0;int j=1;
        for(auto &each:nums){
            if(each>0){
               ans[i]=each;
               i=i+2;
            }
            else{
               ans[j]=each;
               j=j+2;
            }
        }
        return ans;
    }
};