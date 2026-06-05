class Solution {
public:
        // vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        // vector<string>ans;
        // for(int i=0;i<words.size();i++){
        //     string s=words[i];
        //     string t=pattern;
        //     char arr[26]={0};
        //     char brr[26]={0};
        //     bool flag=1;
        //     for(int i=0;i<s.length();i++){
        //     if(!arr[s[i]-'a']&&!brr[t[i]-'a']){
        //         arr[s[i]-'a']=t[i];
        //         brr[t[i]-'a']=s[i];
        //     }
        //     else{
        //         if(arr[s[i]-'a']!=t[i]){
        //         flag=0;
        //         break;
        //         }
        //     }
        // }
        // if(flag)
        // ans.push_back(s);
        // }
        // return ans;
        //  }


    void normalise(string &s){
       char arr[26]={0};
       char start='a';
       for(int i=0;i<s.length();i++){//
           if(!arr[s[i]-'a']){
               arr[s[i]-'a']=start;
               s[i]=start;
               start++;
           }
           else{
              s[i]=arr[s[i]-'a'];
           }
       }
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        normalise(pattern);
        vector<string>ans;
        for(int i=0;i<words.size();i++){
            string ccopy=words[i];
            normalise(ccopy);
            if(ccopy.compare(pattern)==0)
            ans.push_back(words[i]);
        }
        return ans;
    }
};