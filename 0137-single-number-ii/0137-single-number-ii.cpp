class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // for(int i=0;i<32;i++){
        //     for(auto &each:nums){

        //     }
        // }


        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size();i++){
        //     if(i>0&&nums[i]==nums[i-1]) continue;
        //     if(i+1<nums.size()&&nums[i]==nums[i+1]) continue;
        //     return nums[i];
        // }
        // return -1;


        int ans=0;
        for(int i=0;i<32;i++){
            int c=0;
            int c1=0;
            for(auto &each:nums){
                if((each>>i)&1){
                    c++;
                }
                else{
                    c1++;
                }
            }
            c=c%3;
            c1=c1%3;
            if(c!=0){
               ans=(ans|(1<<i));
            }
        }
        return ans;
    }
};