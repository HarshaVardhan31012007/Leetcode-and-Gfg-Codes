class Solution {
public:
    int smallestRepunitDivByK(int k) {
         int n=0;
         int ans=0;
         unordered_map<int,bool>mpp;
         while(1){
            n=(n*10+1)%k;
            if(mpp.count(n)) break;
            ans++;
            if(n==0) return ans;
            mpp[n]=1;
         }
         return -1;
    }
};