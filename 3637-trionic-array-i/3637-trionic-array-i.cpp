class Solution {
public:
    bool isTrionic(vector<int>& nums) {
       int i=0;
       while(i+1<nums.size()&&nums[i]<nums[i+1]){
        i++;
       } 
       if(i==nums.size()-1) return false;
       while(i!=0&&i+1<nums.size()&&nums[i]>nums[i+1]){
        i++;
       } 
       if(i==nums.size()-1) return false;
       while(i>=2&&i+1<nums.size()&&nums[i]<nums[i+1]){
        i++;
       }
       return i==nums.size()-1;
    }
};