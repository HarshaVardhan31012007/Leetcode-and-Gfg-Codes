class Solution {
public:
    // void find(string &s,string &part){
    //     int idx=s.find(part);
    //     if(idx==string::npos) return;
    //     s=s.substr(0,idx)+s.substr(idx+part.length());
    //     find(s,part);
    // }
    // string removeOccurrences(string s, string part) {
    //     find(s,part);
    //     return s;
    // }


   
    // string removeOccurrences(string s, string part) {
    //     int idx=s.find(part);
    //     while(idx!=string::npos){
    //         s=s.erase(idx,part.length());
    //         idx=s.find(part);
    //     }
    //     return s;
    // }



    string removeOccurrences(string s, string part) {
        // int m=s.length();
        // int n=part.length();
        // string ans;
        // for(int i=0;i<m;i++){
        //     ans+=s[i];
        //     int len=ans.length();
        //     if(len>=n&&ans.compare(len-n,n,part)==0){
        //         ans.erase(len-n,n);
        //     }
        // }
        // return ans;


        int m=s.length();
        int n=part.length();
        int j=0;
        for(int i=0;i<m;i++){
            s[j++]=s[i];
            if(j>=n&&s.compare(j-n,n,part)==0){
               j-=n;
            }
        }
        return s.substr(0,j);
    }
};