class Solution {
public:
    // bool solve(string &s,int i,vector<int>&dp,unordered_set<string>&st){
    //     if(i>=s.length()) return true;
    //     if(dp[i]!=-1) return dp[i];
    //     string temp="";bool ans=false;
    //     for(int j=i;j<s.length();j++){
    //         temp+=s[j];
    //         if(st.find(temp)!=st.end()){
    //            ans=ans||solve(s,j+1,dp,st);
    //         }
    //     }
    //     return dp[i]=ans;
    // }
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     unordered_set<string>st;
    //     for(auto &each:wordDict)
    //     st.insert(each);
    //     vector<int>dp(s.length()+1,-1);
    //     return solve(s,0,dp,st);
    // }


    
    
    //  bool solve(string &s,int i,vector<int>&dp,unordered_map<string,int>&mpp){
    //     if(i>=s.length()) return true;
    //     if(dp[i]!=-1) return dp[i];
    //     string temp="";bool ans=false;
    //     for(int j=i;j<s.length();j++){
    //         temp+=s[j];
    //         if(mpp.find(temp)!=mpp.end()){
    //            ans=ans||solve(s,j+1,dp,mpp);
    //         }
    //     }
    //     return dp[i]=ans;
    // }
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     unordered_map<string,int>mpp;
    //     for(auto &each:wordDict)
    //     mpp[each]=1;
    //     vector<int>dp(s.length()+1,-1);
    //     return solve(s,0,dp,mpp);
    // }



      class Trie{
         public:
         char data;
         Trie* children[26];
         bool isterminal;
         Trie(char data){
            this->data=data;
            for(int i=0;i<26;i++)
            this->children[i]=NULL;
            this->isterminal=false;
         }
         bool find(Trie* &root,string &s,int i){
            if(i>=s.length()) return root->isterminal;
            if(root->children[s[i]-'a']!=NULL)
            return find(root->children[s[i]-'a'],s,i+1);
            else
            return false;
         }
      };
      bool solve(string &s,int i,vector<int>&dp,Trie* &root){
        if(i>=s.length()) return true;
        if(dp[i]!=-1) return dp[i];
        string temp="";bool ans=false;
        for(int j=i;j<s.length();j++){
            temp+=s[j];
            if(root->find(root,temp,0)){
               ans=ans||solve(s,j+1,dp,root);
            }
        }
        return dp[i]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* root=new Trie('-');
        for(auto &each:wordDict){
            Trie* curr=root;
            for(int i=0;i<each.length();i++){
               if(curr->children[each[i]-'a']==NULL)
               curr->children[each[i]-'a']=new Trie(each[i]);
               curr=curr->children[each[i]-'a'];
            }
            curr->isterminal=true;
        }
        vector<int>dp(s.length()+1,-1);
        return solve(s,0,dp,root);
    }
};