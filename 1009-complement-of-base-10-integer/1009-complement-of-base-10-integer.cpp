class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        long long pos=log2(n);
        pos++;
        long long temp=(1<<pos);
        temp--;
        return (~n)&temp;
    }
};