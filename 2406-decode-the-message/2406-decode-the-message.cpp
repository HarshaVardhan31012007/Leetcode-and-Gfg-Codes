class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>mpp;
        int j=0;
        for(int i=0;i<key.length();i++){
            if(key[i]==' ') continue;
            if(mpp.find(key[i])==mpp.end()){
                mpp[key[i]]=j+'a';
                j++;
            }
        }
        for(int i=0;i<message.length();i++){
           if(message[i]==' ') continue;
           message[i]=mpp[message[i]];
        }
        return message;
    }
};