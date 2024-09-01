class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int zc=0,oc=0,tc=0;
        while(i<n){
          if(nums[i]==0)
          zc++;
          else if(nums[i]==1)
          oc++;
          else if(nums[i]==2)
          tc++;
          i++;
        }
        i=0;
        while(zc--){
            nums[i]=0;
            i++;
        }
       while(oc--){
        nums[i]=1;
        i++;
       }
       while(tc--){
        nums[i]=2;
        i++;
       }
    
        
    }
};