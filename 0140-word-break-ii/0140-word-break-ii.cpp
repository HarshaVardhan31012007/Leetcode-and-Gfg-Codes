class Solution {
public:
//    bool check(string &temp,vector<string>& wordDict){
//         for(auto &i:wordDict){
//            if(i==temp)
//            return true;
//         }
//         return false;
//     }
//     void solve(int i,string &s,vector<string>& wordDict,vector<string>&ans,string t){
//         if(i==s.size()) {
//             t.pop_back();
//             ans.push_back(t);
//         }
//         string temp="";
//         for(int j=i;j<s.length();j++){
//             temp=temp+s[j];
//             if(check(temp,wordDict)){
//              solve(j+1,s,wordDict,ans,t+temp+" ");
//             }
//         }
//     }
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
//         vector<string>ans;
//         string t="";
//         solve(0,s,wordDict,ans,t);
//         return ans;
//     }



    unordered_map<string,bool>mpp;
    void solve(int i,string &s,vector<string>& wordDict,vector<string>&ans,string t){
        if(i==s.size()) {
            t.pop_back();
            ans.push_back(t);
        }
        string temp="";
        for(int j=i;j<s.length();j++){
            temp=temp+s[j];
            if(mpp[temp]==1){
             solve(j+1,s,wordDict,ans,t+temp+" ");
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        string t="";
        for(auto &i:wordDict)
        mpp[i]=1;
        solve(0,s,wordDict,ans,t);
        return ans;
    }
};