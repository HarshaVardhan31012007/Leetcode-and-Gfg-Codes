class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        int ans=0;int sign=1;
        int i=0;
        while(i<n&&s[i]==' '){
            i++;
        }
        if(s[i]=='-'||s[i]=='+'){
            sign=(s[i]=='+'?1:-1); 
            i++;
        }
        while(i<n&&isdigit(s[i])){
            int digit=sign*(s[i]-'0');
            if(ans>INT_MAX/10||ans==INT_MAX/10&&digit>7) return INT_MAX;
            if(ans<INT_MIN/10||ans==INT_MIN/10&digit<-8) return INT_MIN;
            ans=ans*10+sign*(s[i]-'0');
            i++;
        }
        return ans;
    }
};