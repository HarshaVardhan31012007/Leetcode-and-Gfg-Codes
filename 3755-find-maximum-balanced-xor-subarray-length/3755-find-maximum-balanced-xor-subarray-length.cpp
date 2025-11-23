class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        // int n=nums.size();
        // vector<int>evens(n,0);
        // vector<int>odds(n,0);
        // int xo=nums[0];
        // evens[0]=((nums[0]&1)?0:1);
        // odds[0]=((nums[0]&1)?1:0);
        // unordered_map<int,vector<int>>mpp;
        // int ans=0;
        // mpp[xo].push_back(0);
        // for(int i=1;i<n;i++){
        //      xo=xo^nums[i];
        //      if(nums[i]&1){
        //          odds[i]+=odds[i-1]+1;
        //          evens[i]+=evens[i-1];
        //      }
        //      else{
        //          odds[i]+=odds[i-1];
        //          evens[i]+=evens[i-1]+1;
        //      }
        //      if(xo==0&&evens[i]==odds[i]){
        //           ans=max(ans,i+1);
        //      }
        //      if(mpp.count(xo)==1){
        //          auto &v=mpp[xo];
        //          for(auto &each:v){
        //              int even=evens[i]-evens[each];
        //              int odd=odds[i]-odds[each];
        //              if(even==odd){
        //                  ans=max(ans,i-each);
        //              }
        //          }
        //      }
        //      mpp[xo].push_back(i);
        // }
        // return ans;



        int n=nums.size();
        map<pair<int,int>,int>mpp;

        int ans=0;
        int xo=nums[0];
        int even=((nums[0]&1)?0:1);
        int odd=((nums[0]&1)?1:0);
        mpp[{xo,even-odd}]=0;

        for(int i=1;i<n;i++){
             xo=xo^nums[i];
             even+=((nums[i]&1)?0:1);
             odd+=((nums[i]&1)?1:0);

             if(!xo&&even==odd)
                ans=max(ans,i+1);
             if(mpp.count({xo,even-odd})){
                int idx=mpp[{xo,even-odd}];
                ans=max(ans,i-idx);
             }
             else{
                 mpp[{xo,even-odd}]=i;
             }
        }
        return ans;
    }
};