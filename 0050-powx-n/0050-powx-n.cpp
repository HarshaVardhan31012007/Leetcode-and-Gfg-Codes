class Solution {
public:
    double myPow(double x, int n) {
        double product=1;
        if(n==0) return 1.0;
        if(x==0) return 0.0;
        if(x==1.0) return 1.0;
        if(x==-1.0&&n%2==0) return 1.0;
        if(x==-1.0&&n%2!=0) return -1.0;
         if(n==INT_MIN){
          if(x==1.0||x==-1.0)
          return 1.0;
          else
          return 0.0;
         }
         if(n==INT_MAX&&(x==1.0||x==-1.0)){
            return x;
         }
        int N=abs(n);
        if(x==1.0)
        return 1.0;
        for(int i=0;i<N;i++){
        product=product*x;
        }
        return (n>0)?product:1/product;
    }
};