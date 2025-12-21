class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int count=0;
        while(i<s.length()&&s[i]!=' '){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                count++;
            i++;
        }
        for(int j=i;j<s.length();j++){
            int c=0;
            while(j<s.length()&&s[j]!=' '){
                 if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')
                    c++;
                 j++;
            }
            if(c==count){
                reverse(s.begin()+i,s.begin()+j);
            }
            i=j+1;
        }
        return s;
    }
};