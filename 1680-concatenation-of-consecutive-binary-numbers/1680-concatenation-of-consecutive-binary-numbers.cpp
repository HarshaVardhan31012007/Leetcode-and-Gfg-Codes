class Solution {
public:
    const int mod=1e9+7;
    int concatenatedBinary(int n) {
        long long int ans=0;
        int c=1;
        for(int num=n;num>=1;num--){
            int x=num;
            while(x){
                int digit=(x&1);
                if(digit){
                    ans=(ans+(1LL*c*digit)%mod)%mod;
                }
                else{
                   ans=(ans+(1LL*c*digit)%mod)%mod;
                }
                x=x>>1;
                c=(2LL*c)%mod;
            }
        }
        return ans;
    }
};