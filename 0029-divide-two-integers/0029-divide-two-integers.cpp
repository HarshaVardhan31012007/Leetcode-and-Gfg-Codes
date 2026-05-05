class Solution {
public:
    int divide(long long int dividend,long long int divisor) {
        long long int a=dividend;
        long long int b=divisor;
        divisor=abs(divisor);
        dividend=abs(dividend);
        long long int count=0;
        while(dividend>=divisor){
            long long int temp=1;
            while(temp*divisor<=dividend){
                temp=(temp<<1);
            }
            temp=temp>>1;
            count+=temp;
            dividend-=temp*divisor;
        }
        if((a^b)<0) count=-count;
        if(count>INT_MAX) return INT_MAX;
        if(count<INT_MIN) return INT_MIN;
        return count;
    }
};