class Solution {
public:
    // int find(int n){
    //     int c=0;
    //     while(n>0){
    //         c++;
    //         n=n/10;
    //     }
    //     return c;
    // }
    int countCommas(int n) {
        int sum=0;
        // for(int i=1000;i<=n;i++){
        //     int digits=find(i);
        //     sum+=(digits-1)/3;
        // }
        // return sum;
        if(n>=1000&&n<=9999) sum+=n-1000+1;
        if(n>=10000&&n<=99999) sum+=n-10000+1+9000;
        if(n==100000) sum+=1+9000+90000;
        return sum;
    }
};