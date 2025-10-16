class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
       for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                nums[i]=nums[i]%value;
            }
            else{
               nums[i]=abs(nums[i]);
               nums[i]=nums[i]%value;
               if(nums[i]>0)
               nums[i]=-nums[i]+value;
            }
       }
       sort(nums.begin(),nums.end());
       vector<int>temp(nums.size());
       for(int j=0;j<nums.size();j++){
            if(j>0&&nums[j]==nums[j-1]){
               temp[j]=temp[j-1]+value;
            }
            else
            temp[j]=nums[j];
       }
       int ans=0;
       sort(temp.begin(),temp.end());
        for(int j=0;j<temp.size();j++){
           if(temp[j]==ans)
           ans++;
           else
           return ans;
       }
       return ans;
    }
};