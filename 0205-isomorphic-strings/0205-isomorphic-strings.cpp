class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>mpp1;
        map<char,char>mpp2;
        for(int i=0;i<s.length();i++){
            if(!mpp1.count(s[i])&&!mpp2.count(t[i])){
                mpp1[s[i]]=t[i];
                mpp2[t[i]]=s[i];
            }
            else if(mpp1.count(s[i])&&mpp1[s[i]]==t[i]) continue;
            else return false;
        }
        return true;
    }
};