class Solution {
public:
    bool isPowerOfThree(int n) {
        // if(n<1) return false;
        // while(n%3==0)
        // n=n/3;
        // return n==1;
         
         //n should be prime
        // if(n<=0) return false;
        // int a=pow(3,19);// by binary search nikal sakhte hai max poer of 3 less than or equal to INT_MAX
        // return a % n ==0; 

        // if(n==1) return true;
        // if(n==0||n%3!=0) return false;
        // return isPowerOfThree(n/3);


        if(n<=0) return false;
        if(n==1) return true;
        double ans=log10(n)/log10(3);
        return (int)ans==ans;
    }
};