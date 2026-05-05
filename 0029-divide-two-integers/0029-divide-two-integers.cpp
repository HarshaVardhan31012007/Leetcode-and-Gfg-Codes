class Solution {
public:
    // int divide(long long int dividend,long long int divisor) {
    //     long long int a=dividend;
    //     long long int b=divisor;
    //     divisor=abs(divisor);
    //     dividend=abs(dividend);
    //     long long int count=0;
    //     while(dividend>=divisor){
    //         long long int temp=1;
    //         while(temp*divisor<=dividend){
    //             temp=(temp<<1);
    //         }
    //         temp=temp>>1;
    //         count+=temp;
    //         dividend-=temp*divisor;
    //     }
    //     if((a^b)<0) count=-count;
    //     if(count>INT_MAX) return INT_MAX;
    //     if(count<INT_MIN) return INT_MIN;
    //     return count;
    // }


    int divide(int dividend,int divisor) {
        if(dividend==divisor) return 1;
        if(divisor==1) return dividend;
        if(dividend==INT_MIN&&divisor==-1) return INT_MAX;
        long a=dividend;
        long b=divisor;
        bool isPositive=((a^b)>=0);
        a=abs(a);
        b=abs(b);
        long ans=0;
        while(a>=b){
            long count=0;
            while(a>=(b<<(count+1))){
                count++;
            }
            ans+=(1<<count);
            a-=(b<<(count));
        }
        return isPositive?ans:-ans;
    }
};