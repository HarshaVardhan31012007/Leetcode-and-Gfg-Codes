class Solution {
public:
    long long find(long long n){
        long long c=0;
        while(n>0){
            c++;
            n=n/10;
        }
        return c;
    }
    long long countCommas(long long n) {
        vector<long long>digits={0,0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5};
        long long ndigits=find(n);
        long long sum=0;long long c=1000;
        for(int i=4;i<ndigits;i++){
            sum+=9*c*digits[i];
            c=c*10;
        }
        if(ndigits>=4)
        sum+=(n-c+1)*digits[ndigits];
        return sum;
    }
};
