class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // vector<long long int>prefix(nums.size(),0);
        // prefix[0]=nums[0];
        // for(int i=1;i<nums.size();i++){
        //     prefix[i]=nums[i]+prefix[i-1];
        // }
        // for(int i=nums.size()-1;i>=2;i--){
        //      if(nums[i]<prefix[i-1])
        //      return prefix[i];
        // }
        // return -1;



        sort(nums.begin(),nums.end());
        long perimeter=0;
        long sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<sum){
                perimeter=nums[i]+sum;
            }
            sum+=nums[i];
        }
        return perimeter==0?-1:perimeter;
    }
};