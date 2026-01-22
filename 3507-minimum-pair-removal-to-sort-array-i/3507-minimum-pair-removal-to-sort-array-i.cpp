class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        // int ans=0;
        // while(1){
        //     int idx=-1;int sum=1e5;bool flag=1;
        //     for(int i=0;i<(int)nums.size()-1;i++){
        //         if(nums[i]+nums[i+1]<sum){
        //             sum=nums[i]+nums[i+1];
        //             idx=i;
        //         }
        //         if(nums[i+1]<nums[i])
        //         flag=0;
        //     }
        //     if(flag)
        //     return ans;
        //     ans++;
        //     vector<int>temp;
        //     for(int i=0;i<nums.size();i++){
        //         if(idx!=i)
        //         temp.push_back(nums[i]);
        //         else
        //         temp.push_back(nums[i]+nums[++i]);
        //     }
        //     nums=temp;
        // }
        // return ans;



        //  int ans=0;
        // while(1){
        //     int idx=-1;int sum=1e5;bool flag=1;
        //     for(int i=0;i<(int)nums.size()-1;i++){
        //         if(nums[i]+nums[i+1]<sum){
        //             sum=nums[i]+nums[i+1];
        //             idx=i;
        //         }
        //         if(nums[i+1]<nums[i])
        //         flag=0;
        //     }
        //     if(flag)
        //     return ans;
        //     ans++;
        //     nums[idx+1]+=nums[idx];
        //     nums.erase(nums.begin()+idx,nums.begin()+idx+1);
        // }
        // return ans;



         int ans=0;
        while(1){
            int idx=-1;int sum=1e5;bool flag=1;
            for(int i=0;i<(int)nums.size()-1;i++){
                if(nums[i]+nums[i+1]<sum){
                    sum=nums[i]+nums[i+1];
                    idx=i;
                }
                if(nums[i+1]<nums[i])
                flag=0;
            }
            if(flag)
            return ans;
            ans++;
            nums[idx+1]+=nums[idx];
            nums.erase(nums.begin()+idx,nums.begin()+idx+1);
        }
        return ans;
    }
};