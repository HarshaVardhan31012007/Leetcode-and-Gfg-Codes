class Solution {
public:
    int bitwiseComplement(int n) {
        // int m=n;
        // int mask=0;
        // if(n==0)
        // return 1;
        // while(m!=0){
        //     mask=(mask<<1)|1;
        //     m=m>>1;
        // }
        // return ~n&mask;

        int c=1;int ans=0;
        if(!n) return 1;
        while(n){
            int digit=n%2;
            if(!digit)
            ans+=c*1;
            c=c*2;
            n=n/2;
        }
        return ans;
    }
};