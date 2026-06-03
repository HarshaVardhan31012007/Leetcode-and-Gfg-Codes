class Solution {
    public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n=s.length();
        int i=0;int j=0;
        while(j<n){
            while(j<n&&s[j]==' ') j++;
            if(j==n) break;
            int start=i;
            while(j<n&&s[j]!=' '){
                s[i++]=s[j++];
            }
            reverse(s.begin()+start,s.begin()+i);
            while(j<n&&s[j]==' ') j++;
            if(j==n) break;
            s[i++]=' ';
        }
        return s.substr(0,i);
    }
};