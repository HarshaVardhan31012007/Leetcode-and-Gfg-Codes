class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        for(int j=0;j<s.size();j++){
            bool flag=isalpha(s[j])||isdigit(s[j]);
            if(flag){
                s[i]=s[j];
                // if(s[i]>='A'&&s[i]<='Z')
                // s[i]=s[i]-'A'+'a';
                if(isupper(s[i]))
                s[i]=tolower(s[i]);
                i++;
            }
        }
        int j=i-1;
        i=0;
        while(i<j){
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
};