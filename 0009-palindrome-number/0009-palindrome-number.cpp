class Solution {
public:
    int reverseI(int x){
        int ans=0;
        while(x>0){
            int digit=x%10;
            if(ans>INT_MAX/10)
            return -1;
            ans=ans*10+digit;
            x=x/10;
        }
        return ans;
    }
    bool isPalindrome(int x) {
        //m1 integer to string and two pointers
        //m2
        if(x<0) return false;
        int reversex=reverseI(x);
        return x==reversex;
    }
};