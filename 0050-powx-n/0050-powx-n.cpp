class Solution {
public:
    double solve(double x,int n){
        if(n==0) return 1;
        if(n&1)
        return x*solve(x*x,n/2);
        else
        return solve(x*x,n/2);
    }
    double myPow(double x, int n) {
        // double product=1;
        // //cases for decreasing time
        // if(n==0) return 1.0;
        // if(x==0) return 0.0;
        // if(x==1.0) return 1.0;
        // if(x==-1.0&&n%2==0) return 1.0;
        // if(x==-1.0&&n%2!=0) return -1.0;
        // //edge case// store n in long variable to avoid this edge case
        //  if(n==INT_MIN){
        //   if(x==1.0||x==-1.0)
        //   return 1.0;
        //   else
        //   return 0.0;
        //  }
        //  //this has to be included to dec time if above cases are not included
        // //  if(n==INT_MAX&&(x==1.0||x==-1.0)){
        // //     return x;
        // //  }
        // int N=abs(n);
        // if(x==1.0)
        // return 1.0;
        // for(int i=0;i<N;i++){
        // product=product*x;
        // }
        // return (n>0)?product:1/product;

        //method 2
        //cases for decreasing time
        // if(n==0) return 1.0;
        // if(n==1) return x;
        // if(x==0) return 0.0;
        // if(x==1.0) return 1.0;
        // if(x==-1.0&&n%2==0) return 1.0;
        // if(x==-1.0&&n%2!=0) return -1.0;
        
        // long newN=n;
        // if(newN<0){
        //     x=1/x;
        //     newN=-newN;
        // }
        // double ans=1;
        // while(newN>0){
        //     if(newN%2==1){
        //         ans=ans*x;
        //     }
        //     x*=x;
        //     newN=newN/2;
        // }
        // return ans;


        // if(n==0) return 1.0;
        // if(n==1) return x;
        // if(x==0) return 0.0;
        // if(x==1.0) return 1.0;
        // if(x==-1.0&&(n&1)) return -1.0;
        // if(x==-1.0&&!(n&1)) return 1.0;
        // double ans=1;
        // long newN=n;
        // if(newN<0){
        //     x=1/x;
        //     newN=-newN;
        // }
        // while(newN>0){
        //     if(newN&1){
        //         ans=ans*x;
        //     }
        //     x=x*x;
        //     newN=newN>>1;
        // }
        // return ans;



        //recursion
        long int newn=n;
        if(n==0) return 1.0;
        if(n==1) return x;
        if(x==0.0) return 0.0;
        if(x==1.0) return 1.0;
        if(x==-1.0&&n%2==0) return 1.0;
        if(x==-1.0&&n%2!=0) return -1.0;
         if(newn<0)
         x=1/x;
         return solve(x,newn);
    }
};