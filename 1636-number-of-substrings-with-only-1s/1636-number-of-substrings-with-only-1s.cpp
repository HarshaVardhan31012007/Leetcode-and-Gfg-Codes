class Solution {
public:
    const int mod=1e9+7;
    int numSub(string s) {
        int ans=0;int curr=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1') curr=(curr+1)%mod;
            else{
            // ans=(ans+(curr*(curr+1))%mod)%mod;
            for(int j=1;j<=curr;j++){
                ans=(ans+j)%mod;
            }
            curr=0;
            }
        }
        // ans=(ans+(curr*(curr+1))%mod)%mod;
        for(int j=1;j<=curr;j++){
                ans=(ans+j)%mod;
        }
        return ans;
    }
};