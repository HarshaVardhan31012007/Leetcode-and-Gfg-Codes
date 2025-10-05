class Solution {
public:
    string removeSubstring(string s, int k) {
         string temp="";
         for(int i=0;i<k;i++){
             temp+='(';
         }
         for(int i=0;i<k;i++){
             temp+=')';
         }
        string str="";
        for(int i=0;i<s.length();i++){
            str+=s[i];
            while(str.length()>=2*k&&!str.compare(str.length()-2*k,2*k,temp)){
                int count=2*k;
                while(count--)
                str.pop_back();
            }
        }
        return str;
    }
};