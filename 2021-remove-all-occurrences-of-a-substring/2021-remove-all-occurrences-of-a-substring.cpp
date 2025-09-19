class Solution {
public:
    // void solve(string &s,string &part){
          
    //     auto idx=s.find(part);
    //     if(idx!=string::npos){
    //         string left=s.substr(0,idx);
    //         string right=s.substr(idx+part.size(),s.size());
    //         s=left+right;
    //         solve(s,part);
    //     }
    //     else
    //     return;
    // }
    string removeOccurrences(string s, string part) {


    // auto idx=s.find(part);
    // while(idx!=string::npos){
    //     s.erase(idx,part.size());
    //     idx=s.find(part);
    // }
    //  return s;
     
    //  solve(s,part);
    //   return s;


    // int i=0;int m=part.length();
    // for(int j=0;j<s.length();j++){
    //     s[i]=s[j];
    //     if(i>=m-1&&s.substr(i-m+1,m)==part)
    //     i=i-m;
    //     i++;
    // }
    //    return s.substr(0,i);

    
    int i=0;int m=part.length();
    for(int j=0;j<s.length();j++){
        s[i]=s[j];
        if(i>=m-1&&s.compare(i-m+1,m,part)==0)
        i=i-m;
        i++;
    }
       return s.substr(0,i);
    }
};