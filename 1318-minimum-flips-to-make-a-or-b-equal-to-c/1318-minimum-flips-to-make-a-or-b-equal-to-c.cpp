class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        for(int i=31;i>=0;i--){
            if((c>>i)&1){
                int a1=((a>>i)&1);
                int b1=((b>>i)&1);
                if(!a1&&!b1){
                   ans++;
                }
            }
            else{
                int a1=((a>>i)&1);
                int b1=((b>>i)&1);
                ans+=(a1+b1);
            }
        }
        return ans;
    }
};