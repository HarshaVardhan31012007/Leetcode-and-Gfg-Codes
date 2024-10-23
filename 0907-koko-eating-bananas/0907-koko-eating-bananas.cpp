class Solution {
public:
    bool findtotalhours(vector<int>&piles,int h,int k){
       int n=piles.size();
       long sum=0;
       for(int i=0;i<n;i++){
          sum=sum+ceil(piles[i]/(double)k);
       }
       return sum<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
      int s=1;
      int e=*max_element(piles.begin(),piles.end());
      int ans=0;
      while(s<=e){
        int mid=s+(e-s)/2;
        int k=mid;
        if(findtotalhours(piles,h,k)){
             ans=mid;
             e=mid-1;
        }
        else
        s=mid+1;
      }
      return ans;
    }
};