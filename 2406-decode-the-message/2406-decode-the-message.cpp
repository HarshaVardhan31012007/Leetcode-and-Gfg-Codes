class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>mpp;
        char start='a';
        int i=0;
        char d=' ';
        mpp[d]=d;
        while(start<='z'){
            char c=key[i];
            if(mpp.find(c)!=mpp.end())
            i++;
            else{
                mpp[c]=start;
                start++;
                i++;
            }
        }
        string s="";
        for(int i=0;i<message.length();i++){
             int mc=message[i];
             int mppc=mpp[mc];
             s.push_back(mppc);
        }
        return s;
    }
};