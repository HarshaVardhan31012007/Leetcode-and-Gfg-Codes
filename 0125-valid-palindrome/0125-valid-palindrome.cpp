class Solution {
public:
    bool isPalindrome(string s) {
        //int n=s.size();
        for(int i=0;i<s.size();i++){
            if(s[i]>='A'&&s[i]<='Z')
            s[i]=s[i]-'A'+'a';
        }
        for(int i=0;i<s.size();i++){
           
           bool a=(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9');
           if(a==0){
            s.erase(i,1);
            i--;
           }
        }
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else
              return false;
        }
        return true;
    }
};