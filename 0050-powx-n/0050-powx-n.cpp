class Solution {
public:
    double myPow(double x, int n) {
        double product=1;
         if(n==INT_MIN){
          if(x==1||x==-1)
          return 1;
          else
          return 0;
         }
         if(n==INT_MAX&&(x==1||x==-1)){
            return x;
         }
        int N=abs(n);
        if(x==1)
        return 1;
        for(int i=0;i<N;i++){
        product=product*x;
        }
        return (n>0)?product:1/product;
    }
};