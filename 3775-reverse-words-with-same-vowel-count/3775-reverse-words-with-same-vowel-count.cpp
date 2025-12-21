class Solution {
public:
    // string reverseWords(string s) {
    //     int i=0;
    //     int count=0;
    //     while(i<s.length()&&s[i]!=' '){
    //         if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
    //             count++;
    //         i++;
    //     }
    //     for(int j=i;j<s.length();j++){
    //         int c=0;
    //         while(j<s.length()&&s[j]!=' '){
    //              if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')
    //                 c++;
    //              j++;
    //         }
    //         if(c==count){
    //             reverse(s.begin()+i,s.begin()+j);
    //         }
    //         i=j+1;
    //     }
    //     return s;
    // }


    int find(string &s){
        int count=0;
        for(auto &each:s){
            each=tolower(each);
            if(each=='a'||each=='e'||each=='i'||each=='o'||each=='u')
            count++;
        }
        return count;
    }
    string reverseWords(string s) {
        stringstream ss(s);
        string word,result;
        ss>>word;
        int count=find(word);
        result+=word;
        while(ss>>word){
            if(find(word)==count){
                reverse(word.begin(),word.end());
            }
             result+=" "+word;
        }
        return result;
    }
};