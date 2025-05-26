class Solution {
public:
    bool possible(int k,vector<int>&piles,int h){
       for(int i=0;i<piles.size();i++){
          h=h-ceil(piles[i]/(double)k);
       }
       return h>=0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=*max_element(piles.begin(),piles.end());
         if(h==piles.size()) return e;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(mid,piles,h)){
               ans=mid;
               e=mid-1;
            }
            else
            s=mid+1;
        }
        return ans;
    }
};