class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for(int b=2;b<=n-2;b++){
            string s="";
            int num=n;
            while(num!=0){
                s+=to_string(num%b);
                num=num/2;
            }
            int i=0;int j=s.length()-1;
            while(i<j){
                if(s[i]==s[j]){
                    i++;j--;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};