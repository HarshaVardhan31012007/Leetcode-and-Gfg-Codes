class Solution {
public:
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
      vector<string>solve(string &s,int i,vector<vector<string>>&dp,Trie* &root){
        if(i>=s.length()) return {""};
        if(!dp[i].empty()) return dp[i];
        string temp="";
        vector<string>ans;
        for(int j=i;j<s.length();j++){
            temp+=s[j];
            if(root->find(root,temp,0)){
               vector<string>temp1=solve(s,j+1,dp,root);
               for(auto &each:temp1){\
                  if(!each.empty())
                  ans.push_back(temp+" "+each);
                  else
                  ans.push_back(temp);
               }
            }
        }
        return dp[i]=ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
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
        vector<vector<string>>dp(s.length()+1);
        vector<string>ans=solve(s,0,dp,root);
        return ans;
    }
};