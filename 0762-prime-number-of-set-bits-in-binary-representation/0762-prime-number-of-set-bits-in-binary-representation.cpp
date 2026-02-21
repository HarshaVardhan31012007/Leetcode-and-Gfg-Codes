class Solution {
public:
    // int countPrimeSetBits(int left, int right) {
    //     int bits=log2(right);
    //     vector<bool>isprime(bits+1,1);
    //     isprime[0]=0;isprime[1]=0;
    //     for(int i=2;i*i<=(bits+1);i++){
    //         for(int j=i*i;j<=(bits+1);j+=i){
    //             isprime[j]=0;
    //         }
    //     }
    //     int ans=0;
    //     for(int i=left;i<=right;i++){
    //         int c=__builtin_popcount(i);
    //         if(isprime[c]){
    //             ans++;
    //         }
    //     }
    //     return ans;
    // }



    int countPrimeSetBits(int left, int right) {
        unordered_set<int>st({2,3,5,7,11,13,17,19});
        int ans=0;
        for(int i=left;i<=right;i++){
            int c=__builtin_popcount(i);
            if(st.count(c)){
                ans++;
            }
        }
        return ans;
    }
};