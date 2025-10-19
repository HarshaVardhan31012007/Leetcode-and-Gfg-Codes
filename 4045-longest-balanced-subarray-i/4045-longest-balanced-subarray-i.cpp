class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        // int ans=0;
        // for(int i=0;i<nums.size();i++){
        //     int o=0;int e=0;
        //     unordered_map<int,bool>mpp;
        //     for(int j=i;j<nums.size();j++){
        //          if(j>0&&mpp.count(nums[j])){
        //             if(e==o&&e!=0&&o!=0)
        //             ans=max(ans,j-i+1);
        //              continue;
        //          }
        //          if(nums[j]%2==0)
        //              e++;
        //         else
        //              o++;
        //         mpp[nums[j]]=1;
        //         if(e==o)
        //             ans=max(ans,j-i+1);
        //     }
        // }
        // return ans;



        int ans=0;
        for(int i=0;i<nums.size();i++){
            int o=0;int e=0;
            unordered_set<int>even,odd;
            for(int j=i;j<nums.size();j++){
                if(nums[j]&1)
                odd.insert(nums[j]);
                else
                even.insert(nums[j]);
                if(even.size()==odd.size())
                    ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};