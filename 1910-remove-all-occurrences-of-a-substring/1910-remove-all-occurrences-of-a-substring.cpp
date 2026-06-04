class Solution {
public:
    void find(string &s,string &part){
        int idx=s.find(part);
        if(idx==string::npos) return;
        s=s.substr(0,idx)+s.substr(idx+part.length());
        find(s,part);
    }
    string removeOccurrences(string s, string part) {
        find(s,part);
        return s;
    }


   
    // string removeOccurrences(string s, string part) {
    //     int idx=s.find(part);
    //     while(idx!=string::npos){
    //         s=s.erase(idx,part.length());
    //         idx=s.find(part);
    //     }
    //     return s;
    // }
};