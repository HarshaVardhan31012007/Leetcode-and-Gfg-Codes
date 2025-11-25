class Solution {
public:
    int smallestRepunitDivByK(int k) {
        //  int n=0;
        //  int ans=0;
        //  unordered_map<int,bool>mpp;
        //  while(1){
        //     n=(n*10+1)%k;
        //     if(mpp.count(n)) break;
        //     ans++;
        //     if(n==0) return ans;
        //     mpp[n]=1;
        //  }
        //  return -1;

         int n=0;
         int ans=0;
         unordered_set<int>st;
         while(1){
            n=(n*10+1)%k;
            ans++;
            if(n==0) return ans;
            if(st.find(n)!=st.end()){
                break;
            }
            else
            st.insert(n);
         }
         return -1;
    }
};