class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mpp1[256]={0};
        int mpp2[256]={0};
        for(int i=0;i<s.length();i++){
            if(!mpp1[s[i]]&&!mpp2[t[i]]){
                mpp1[s[i]]=t[i];
                mpp2[t[i]]=s[i];
            }
            else if(mpp1[s[i]]==t[i]) continue;
            else return false;
        }
        return true;
    }
};