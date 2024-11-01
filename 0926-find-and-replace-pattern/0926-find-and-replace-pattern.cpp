class Solution {
public:
    void normalise(string &s){
       unordered_map<char,char>mpp;
       char start='a';
       for(int i=0;i<s.length();i++){//
          char c=s[i];
          if(mpp.find(c)==mpp.end()){
            mpp[c]=start;
            start++;
          }
       }

       for(int i=0;i<s.length();i++){
        char mappedcharacter=mpp[s[i]];
        s[i]=mappedcharacter;

       }
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        normalise(pattern);
        vector<string>ans;
        for(int i=0;i<words.size();i++){
           string c=words[i];
           string ccopy=c;
           normalise(ccopy);
        //    if(ccopy==pattern)
        if(ccopy.compare(pattern)==0)
           ans.push_back(c);
        }
        return ans;
    }
};