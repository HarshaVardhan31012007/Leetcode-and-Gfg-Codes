class Solution {
public:
    // bool isAnagram(string s, string t) {
    //     sort(s.begin(),s.end());
    //     sort(t.begin(),t.end());
    //     if(s==t) return true;
    //     return false;
    // }

    bool isAnagram(string s, string t) {
        //for lowecase only
        // int freq[26]={0};
        // for(int i=0;i<s.size();i++){
        //     freq[s[i]-'a']++;
        // }
        // for(int i=0;i<t.size();i++){
        //     freq[t[i]-'a']--;
        // }
        // for(int i=0;i<26;i++){
        //     if(freq[i]!=0) return false;
        // }
        // return true;

        //for characters
        // int freq[256]={0};// as ascii is from 0 to 255
        // for(int i=0;i<s.size();i++){
        //     freq[s[i]]++;
        // }
        // for(int i=0;i<t.size();i++){
        //     freq[t[i]]--;
        // }
        // for(int i=0;i<256;i++){
        //     if(freq[i]!=0) return false;
        // }
        // return true;




        int freq[256]={0};// as ascii is from 0 to 255
        if(s.length()!=t.length()) return false;//for uniocde use char32_t means UTF-32,char64_t means UTF-64
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            if(freq[t[i]]>0)
            freq[t[i]]--;
            else
            return false;
        }
        return true;
    }
};