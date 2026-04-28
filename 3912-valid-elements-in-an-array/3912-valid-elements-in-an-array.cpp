class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int>v(nums.size(),0);
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                v[i]=1;
            }
            maxi=max(maxi,nums[i]);
        }
        maxi=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>maxi){
                v[i]=1;
            }
            maxi=max(maxi,nums[i]);
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(v[i]==1){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};