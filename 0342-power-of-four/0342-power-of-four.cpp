class Solution {
public:
    bool isPowerOfFour(int n) {
        // return (n>0)&&((n&(n-1))==0)&&(n%3==1);
        
        if(n<=0) return false;
        if(n==1) return true;
        double ans=log10(n)/log10(4);
        return (int)ans==ans;
    }
};