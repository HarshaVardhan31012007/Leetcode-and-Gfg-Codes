class Solution {
public:
    bool hasSameDigits(string s) {
        for(int i=0;i<s.length()-2;i++){
            for(int j=0;j<s.length()-i-1;j++){
                int a=s[j]-'0';int b=s[j+1]-'0';
                s[j]=(a+b)%10+'0';
            }
        }
        return s[0]==s[1];



        // long long int c=1;
        // int i=s.length()-1;
        // long long int a=0,b=0;
        // for(int j=1;j<=i;j++){
        //      a=(a%10+(s[j-1]-'a')%10*c%10)%10;
        //      b=(b%10+(s[j]-'a')%10*c%10)%10;
        //      c=c*(i-j)/j;
        // }
        // return a==b;



        // int n=s.length();
        // while(n>2){
        //     for(int i=0;i<n-1;i++){
        //         s[i]=((s[i]-'0')+(s[i+1]-'0'))%10+'0';
        //     }
        //     n--;
        // }
        // return s[0]==s[1];
    }
};