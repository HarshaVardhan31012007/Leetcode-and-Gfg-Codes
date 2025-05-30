class Solution {
public:
    // bool find(char ch,string &vowel){
    //     for(int i=0;i<vowel.size();i++){
    //         if(ch==vowel[i])
    //         return true;
    //     }
    //     return false;
    // }
    // string reverseVowels(string s) {
    //     int i=0;
    //     int j=s.length()-1;
    //     string vowel="aeiouAEIOU";
    //     while(i<j){
    //         bool flag1=find(s[i],vowel);
    //         bool flag2=find(s[j],vowel);
    //         if(flag1==1&&flag2==1){
    //             swap(s[i++],s[j--]);
    //         }
    //         else if(!flag1)
    //         i++;
    //         else
    //         j--;
    //     }
    //     return s;
    // }


    
    // string reverseVowels(string s) {
    //     int i=0;
    //     int j=s.length()-1;
    //     unordered_map<char,bool>mpp;
    //     mpp['a']=1;mpp['e']=1;mpp['i']=0;mpp['o']=1;mpp['u']=1;
    //     mpp['A']=1;mpp['E']=1;mpp['I']=0;mpp['O']=1;mpp['U']=1;
    //     while(i<j){
    //         bool flag1=mpp.find(s[i])!=mpp.end();
    //         bool flag2=mpp.find(s[j])!=mpp.end();
    //         if(flag1==1&&flag2==1){
    //             swap(s[i++],s[j--]);
    //         }
    //         else if(!flag1)
    //         i++;
    //         else
    //         j--;
    //     }
    //     return s;
    // }

    bool find(char ch,string &vowel){
        // ch=tolower(ch);
        // return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';

        ch=toupper(ch);
        return ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U';
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