class Solution {
public:
    string smallestSubsequence(string s) {
        int freq[26]={0};
        int visited[26]={0};
        int n=s.length();
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        string ans="";
        for(int i=0;i<n;i++){
            while(!ans.empty()&&!visited[s[i]-'a']&&freq[ans.back()-'a']>1&&s[i]<ans.back()){
                freq[ans.back()-'a']--;
                visited[ans.back()-'a']=0;
                ans.pop_back();
            }
            if(!visited[s[i]-'a']){
                visited[s[i]-'a']=1;
                ans.push_back(s[i]);
            }
            else
            freq[s[i]-'a']--;
        }
        return ans;
    }
};