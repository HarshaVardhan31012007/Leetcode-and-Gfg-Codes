class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        //   int ans=0;
        //   for(int i=0;i<nums.size();i++){
        //        int rem=nums[i]%3;
        //     //    int op=rem;//nums[i]-rem;
        //     //    if(op>3-rem){//nums[i]+3-rem 
        //     //        op=3-rem;
        //     //    }
        //     //ans+=op;
        //        ans+=min(rem,3-rem);
        //   }
        //   return ans;


        //   int ans=0;
        //   for(int i=0;i<nums.size();i++){
        //         ans+=(nums[i]%3?1:0);
        //   }
        //   return ans;


        return count_if(nums.begin(),nums.end(),[](int num){
            return num%3!=0;
        });
    }
};