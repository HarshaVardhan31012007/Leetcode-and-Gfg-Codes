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
        for(int i=0;i<zc;i++)
        nums[i]=0;
        for(int i=zc;i<zc+oc;i++)
        nums[i]=1;
        for(int i=zc+oc;i<n;i++)
        nums[i]=2;
        
    }
};