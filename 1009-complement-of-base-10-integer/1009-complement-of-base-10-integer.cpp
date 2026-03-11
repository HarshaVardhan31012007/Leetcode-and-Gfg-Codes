class Solution {
public:
    int bitwiseComplement(int n) {
        // if(n==0) return 1;
        // long long pos=log2(n);
        // pos++;
        // long long temp=(1<<pos);
        // temp--;
        // return (~n)&temp;

        if(n==0) return 1;
        int mask=0;
        int m=n;
        while(m!=0){
            mask=(mask<<1)|1;
            m=m>>1;
        }
        return ~n&mask;
    }
};