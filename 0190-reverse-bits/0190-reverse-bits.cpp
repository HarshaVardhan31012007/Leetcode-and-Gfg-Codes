class Solution {
public:
    int reverseBits(int n) {
        int num=0;
        int count=32;
        while(count--){
            int digit=n%2;
            num=num*2+digit;
            n=n/2;
        }
        return num;
    }
};