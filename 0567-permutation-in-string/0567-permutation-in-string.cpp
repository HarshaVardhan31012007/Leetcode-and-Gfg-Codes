class Solution {
public:
bool isSame(unordered_map<char,int>mpp,unordered_map<char,int>wfreq,string s1){
    for(int i=0;i<s1.length();i++){
        if(mpp[s1[i]-'a']!=wfreq[s1[i]-'a'])
        return false;
    }
    return true;
}
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mpp;
        unordered_map<char,int>wfreq;
        for(int i=0;i<s1.length();i++){
            mpp[s1[i]-'a']++;
        }
        int wlen=s1.length();
        for(int i=0;i<s2.length();i++){
            int widx=0;int idx=i;
            while(widx<wlen&&idx<s2.length()){
                wfreq[s2[idx]-'a']++;
                widx++;
                idx++;
            }
            if(isSame(mpp,wfreq,s1)){
                return true;
            }
            wfreq.clear();
        }
        return false;
    }
};