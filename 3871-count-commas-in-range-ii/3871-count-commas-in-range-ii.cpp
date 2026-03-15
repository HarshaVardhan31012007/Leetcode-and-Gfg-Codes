class Solution {
public:
    // long long find(long long n){
    //     long long c=0;
    //     while(n>0){
    //         c++;
    //         n=n/10;
    //     }
    //     return c;
    // }
    // long long countCommas(long long n) {
    //     vector<long long>digits={0,0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5};
    //     long long ndigits=find(n);
    //     long long sum=0;long long c=1000;
    //     for(int i=4;i<ndigits;i++){
    //         sum+=9*c*digits[i];
    //         c=c*10;
    //     }
    //     if(ndigits>=4)
    //     sum+=(n-c+1)*digits[ndigits];
    //     return sum;
    // }



    // long long countCommas(long long n) {
    //    if(n<1000LL) return 0;
    //    else if(n<1000000LL) return n-1000LL+1;
    //    else if(n<1000000000LL) return (n-1000000LL+1)*2+(999999LL-1000LL+1);
    //    else if(n<1000000000000LL)  return (n-1000000000LL+1)*3+(999999999LL-1000000LL+1)*2+(999999LL-1000LL+1);
    //    else if(n<1000000000000000LL) return (n-1000000000000LL+1)*4+(999999999999LL-1000000000LL+1)*3+(999999999LL-1000000LL+1)*2+(999999LL-1000LL+1);
    //    return 5+(999999999999999LL-1000000000000LL+1)*4+(999999999999LL-1000000000LL+1)*3+(999999999LL-1000000LL+1)*2+(999999LL-1000LL+1);
    // }



    long long countCommas(long long n) {
        long long sum=0;
        long long commas=1;
        long long curr=1000;
        while(curr<=n){
            long long end=curr*1000-1;
            if(end<=n)
            sum+=(end-curr+1)*commas;
            else
            sum+=(n-curr+1)*commas;
            curr=curr*1000;
            commas++;
        }
        return sum;
    }
};
