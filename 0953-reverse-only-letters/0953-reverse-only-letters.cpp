class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            //  bool a=s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z';
            //  bool b=s[j]>='a'&&s[j]<='z'||s[j]>='A'&&s[j]<='Z';
            //  if(a==0)
            //  i++;
            //  if(b==0)
            //  j--;
            //  if(a==1&&b==1)
            //  swap(s[i++],s[j--]);


            if(isalpha(s[i])&&isalpha(s[j]))
            swap(s[i++],s[j--]);
            else if(!isalpha(s[i]))
            i++;
            else
            j--;
        }
        return s;
    }
};