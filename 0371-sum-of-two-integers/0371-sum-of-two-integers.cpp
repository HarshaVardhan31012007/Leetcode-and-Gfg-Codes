class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int sum=a^b;
            int carry=a&b;
            a=sum;
            b=carry;
            b=b<<1;
        }
        return a;
    }
};