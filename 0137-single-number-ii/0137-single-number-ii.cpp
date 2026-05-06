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
            for(auto &each:nums){
                if((each>>i)&1){
                    c++;
                }
            }
            c=c%3;
            if(c==1){
               ans=(ans|(1<<i));
            }
        }
        return ans;
    }
};