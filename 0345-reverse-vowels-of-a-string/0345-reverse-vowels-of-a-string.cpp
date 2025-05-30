class Solution {
public:
    bool find(char ch,string &vowel){
        for(int i=0;i<vowel.size();i++){
            if(ch==vowel[i])
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int i=0;
        int j=s.length()-1;
        string vowel="aeiouAEIOU";
        while(i<j){
            bool flag1=find(s[i],vowel);
            bool flag2=find(s[j],vowel);
            if(flag1==1&&flag2==1){
                swap(s[i++],s[j--]);
            }
            else if(!flag1)
            i++;
            else
            j--;
        }
        return s;
    }
};