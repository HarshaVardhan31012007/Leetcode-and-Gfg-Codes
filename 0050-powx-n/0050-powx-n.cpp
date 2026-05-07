class Solution {
public:
    double myPow(double x, int n) {
        // if(n==0) return 1.0;
        // if(x==0.0) return 0.0;
        // if(x==1.0) return 1.0;
        // if(n==1) return x;
        // double ans=x;
        // bool isneg=(n<0);
        // long n1=abs((long long)n);
        // for(int i=1;i<n1;i++){
        //     ans=(ans*x);
        // }
        // return isneg?1/(double)ans:ans;


        if(n==0) return 1.0;
        if(x==0.0) return 0.0;
        if(x==1.0) return 1.0;
        if(n==1) return x;
        double ans=1.0;
        bool isneg=(n<0);
        long n1=abs((long long)n);
        while(n1!=0){
            if(n1&1){
               ans=(ans*x);
            }
            x=(x*x);
            n1=n1/2;
        }
        return isneg?1/(double)ans:ans;
    }
};