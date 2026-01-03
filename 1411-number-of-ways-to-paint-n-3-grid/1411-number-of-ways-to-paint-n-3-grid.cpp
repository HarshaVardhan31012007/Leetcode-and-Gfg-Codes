class Solution {
public:
    const int mod=1e9+7;
    int numOfWays(int n) {
        
        long long int s=6;
        long long int d=6;
        for(int i=2;i<=n;i++){
           long long int d1=((s+d)%mod*2)%mod;
           long long int s1=((d%mod*2)%mod+(s%mod*3)%mod)%mod;
           s=s1%mod;
           d=d1%mod;
        }
        return (s+d)%mod;
    }
};