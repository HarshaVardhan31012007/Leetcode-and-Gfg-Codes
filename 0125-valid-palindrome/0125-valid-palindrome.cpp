class Solution {
public:
    bool isPalindrome(string s) {
        // int i=0;
        // for(int j=0;j<s.size();j++){
        //     bool flag=isalpha(s[j])||isdigit(s[j]);
        //     if(flag){
        //         s[i]=s[j];
        //         // if(s[i]>='A'&&s[i]<='Z')
        //         // s[i]=s[i]-'A'+'a';
        //         if(isupper(s[i]))
        //         s[i]=tolower(s[i]);
        //         i++;
        //     }
        // }
        // int j=i-1;
        // i=0;
        // while(i<j){
        //     if(s[i]!=s[j])
        //     return false;
        //     i++;
        //     j--;
        // }
        // return true;



        //    int i=0;
        // for(int j=0;j<s.size();j++){
        //     bool flag=isalpha(s[j])||isdigit(s[j]);
        //     if(flag){
        //         swap(s[i],s[j]);
        //         if(isupper(s[i]))
        //         s[i]=tolower(s[i]);
        //         i++;
        //     }
        // }
        // int j=i-1;
        // i=0;
        // while(i<j){
        //     if(s[i]!=s[j])
        //     return false;
        //     i++;
        //     j--;
        // }
        // return true;

        int i=0;int j=s.length()-1;
        while(i<j){
           if(!isalpha(s[i])&&!isdigit(s[i])){
             i++;
             continue;
           }
           else if(!isalpha(s[j])&&!isdigit(s[j])){
             j--;
             continue;
           }
           else{
            if(tolower(s[i])!=tolower(s[j]))
            return false;
            i++;j--;
           }
        }
        return true;
    }
};