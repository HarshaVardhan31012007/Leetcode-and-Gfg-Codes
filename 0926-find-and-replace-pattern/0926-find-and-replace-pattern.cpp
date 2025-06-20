class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            string t=pattern;
            int arr[256]={0};
            int brr[256]={0};
            bool flag=1;
            for(int i=0;i<s.length();i++){
            if(!arr[s[i]]&&!brr[t[i]]){
                arr[s[i]]=t[i];
                brr[t[i]]=s[i];
            }
            else{
                if(arr[s[i]]!=t[i])
                flag=0;
            }
        }
        if(flag)
        ans.push_back(s);
        }
        return ans;
    }
};