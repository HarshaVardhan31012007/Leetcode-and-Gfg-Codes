class Solution {
public:
    bool hasSameDigits(string s) {
        for(int i=0;i<s.length()-2;i++){
            for(int j=0;j<s.length()-i-1;j++){
                int a=s[j]-'a';int b=s[j+1]-'a';
                s[j]=(a+b)%10+'a';
            }
        }
        return s[0]==s[1];
    }
};