class Solution {
public:
    const int mod=1e9+7;
    int concatenatedBinary(int n) {
        int ans=0;
        for(int num=1;num<=n;num++){
            int x=num;
            string s="";
            while(x){
                int digit=(x&1);
                if(digit){
                    s+="1";
                }
                else{
                    s+="0";
                }
                x=x>>1;
            }
            reverse(s.begin(),s.end());
            for(auto &each:s){
                ans=(ans<<1)%mod;
                if(each=='1')
                ans++;
            }
        }
        return ans;
    }
};