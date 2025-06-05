class Solution {
public:
    void solve(string &s,string &part){
          
        auto idx=s.find(part);
        if(idx!=string::npos){
            string left=s.substr(0,idx);
            string right=s.substr(idx+part.size(),s.size());
            s=left+right;
            solve(s,part);
        }
        else
        return;
    }
    string removeOccurrences(string s, string part) {


    //  int findkaIndex=s.find(part);
    //     while(1){
    //         if(findkaIndex==string::npos)
    //         return s;
    //         else
    //         s.erase(findkaIndex,part.length());
    //         findkaIndex=s.find(part);
    //     }
    //     return s;

     
     solve(s,part);
      return s;
    }
};