class Solution {
public:
    // int reverseI(int x){
    //     int ans=0;
    //     while(x>0){
    //         int digit=x%10;
    //         if(ans>INT_MAX/10)
    //         return -1;//return 0
    //         ans=ans*10+digit;
    //         x=x/10;
    //     }
    //     return ans;
    // }
    bool isPalindrome(int x) {
        //m1 integer to string and two pointers
        string s=to_string(x);
        int n=s.length();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1])
            return false;
        }
        return true;
        //m2
        // if(x<0) return false;
        // int reversex=reverseI(x);
        // return x==reversex;
    }
};