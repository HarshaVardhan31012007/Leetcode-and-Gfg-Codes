class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0;
        long long sum=0;
        long long num=n;
        long long c=1;
        while(num){
           int digit=num%10;
           sum+=digit;
           x+=c*digit;
           if(digit!=0)
           c=c*10;
           num=num/10;
        }
        return x*sum;
    }
};