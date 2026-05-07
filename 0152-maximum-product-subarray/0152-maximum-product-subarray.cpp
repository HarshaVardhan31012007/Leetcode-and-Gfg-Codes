class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int maxi=INT_MIN;
       int n=nums.size();
       if(n==1) return nums[0];
       int p=1;
       int ans=INT_MIN;
       int start=-1;
       int maxi1=INT_MIN;
       for(int i=0;i<nums.size();i++){
          p=p*nums[i];
          if(p>=0)
          ans=max(ans,p);
          else{
            ans=max(ans,p);
            if(maxi1!=INT_MIN)
            ans=max(ans,p/maxi1);
          }
          if(p<0)
          maxi1=max(maxi1,p);
          if(p==0){
            p=1;
            maxi1=INT_MIN;
          }
       }
       if(maxi==0) return 0;
       return ans;
    }
};