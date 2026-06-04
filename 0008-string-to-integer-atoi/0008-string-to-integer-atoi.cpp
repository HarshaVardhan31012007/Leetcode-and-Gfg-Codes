class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        long long int ans=0;int sign=1;
        int i=0;
        while(i<n&&s[i]==' '){
            i++;
        }
        if(s[i]=='-'||s[i]=='+'){
            sign=(s[i]=='+'?1:-1); 
            i++;
        }
        while(isdigit(s[i])){
            ans=ans*10+(s[i]-'0');
            if(sign*ans>INT_MAX) return INT_MAX;
            if(sign*ans<INT_MIN) return INT_MIN;
            i++;
        }
        return sign*ans;
    }
};