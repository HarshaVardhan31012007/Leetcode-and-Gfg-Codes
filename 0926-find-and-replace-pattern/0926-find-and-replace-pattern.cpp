class Solution {
public:
        vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            string t=pattern;
            char arr[26]={0};
            char brr[26]={0};
            bool flag=1;
            for(int i=0;i<s.length();i++){
            if(!arr[s[i]-'a']&&!brr[t[i]-'a']){
                arr[s[i]-'a']=t[i];
                brr[t[i]-'a']=s[i];
            }
            else{
                if(arr[s[i]-'a']!=t[i])
                flag=0;
            }
        }
        if(flag)
        ans.push_back(s);
        }
        return ans;
         }


    //     void normalise(string &s){
    //    unordered_map<char,char>mpp;
    //    char start='a';
    //    for(int i=0;i<s.length();i++){//
    //       char c=s[i];
    //       if(mpp.find(c)==mpp.end()){
    //         mpp[c]=start;
    //         start++;
    //       }
    //    }

    //    for(int i=0;i<s.length();i++){
    //     char mappedcharacter=mpp[s[i]];
    //     s[i]=mappedcharacter;
    //    }
    // }
    // vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    //     normalise(pattern);
    //     vector<string>ans;
    //     for(int i=0;i<words.size();i++){
    //        string ccopy=words[i];
    //        normalise(ccopy);
    //     //    if(ccopy==pattern)
    //     if(ccopy.compare(pattern)==0)
    //        ans.push_back(c);
    //     }
    //     return ans;
    // }
};