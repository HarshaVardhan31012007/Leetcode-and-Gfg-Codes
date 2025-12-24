class Solution {
public:
    long long lastInteger(long long n) {
        long long a=1;long long d=1;
        long long len=n;
        bool flag=1;
        while(len>1){
            if(!flag&&len%2==0)
            a=a+d;
            d=d*2;
            len=(len+1)/2;
            flag=!flag;
        }
        return a;
    }
};