class Solution {
public:
    char processStr(string s, long long k) {
        long long int len=0;
        int n=s.length();k++;
        for(int i=0;i<n;i++){
            if(isalpha(s[i])){
                len++;
            }
            else if(s[i]=='*'){
                if(len>0) len--;
            }
            else if(s[i]=='#'){
                len+=len;
            }
        }
        if(k>len) return '.';
        int j=n-1;
        while(j>=0){
            if(isalpha(s[j])){
                if(len==k) return s[j];
                len--;
            }
            else if(s[j]=='*'){
                len++;
            }
            else if(s[j]=='#'){
                if(k>len/2){
                    k=(k-len/2);
                }
                len=len/2;
            }
            else if(s[j]=='%'){
                k=(len-k+1);
            }
            j--;
        }
        return '.';
    }
};