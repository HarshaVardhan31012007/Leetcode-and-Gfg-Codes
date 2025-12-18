class Solution {
public:
    // class Trie{
    //     public:

    //     char data;
    //     unordered_map<char,Trie*>children;
    //     bool isterminal;
    //     int index;
        
    //     Trie(char val){
    //         this->data=val;
    //         this->isterminal=false;
    //         this->index=-1;
    //     } 

    //     void insertHelp(Trie* root,string word,int i,int &idx){
    //         if(i>=word.length()){
    //             root->isterminal=true;
    //             root->index=idx;
    //             return;
    //         }
    //         if(root->children.find(word[i])==root->children.end())
    //         root->children[word[i]]=new Trie(word[i]);
    //         insertHelp(root->children[word[i]],word,i+1,idx);
    //     }
    // };
    // void solve(Trie* root,string &pattern,int i,vector<bool>&ans){
    //     if(i>=pattern.size()){
    //        if(root->isterminal)
    //        ans[root->index]=1;
    //        for(int j=0;j<26;j++){
    //            if(root->children.find(j+'a')!=root->children.end()){
    //                solve(root->children[j+'a'],pattern,i,ans);
    //            }
    //        }
    //        return;
    //     }
    //    for(auto &each:root->children){
    //       if(isupper(each.first)){
    //          //should match
    //          if(each.first!=pattern[i]) continue;
    //          solve(each.second,pattern,i+1,ans);
    //       }
    //       else{
    //          //match
    //          if(each.first==pattern[i]){
    //             solve(each.second,pattern,i+1,ans);
    //          }
    //          //not match
    //          else{
    //            solve(each.second,pattern,i,ans);
    //          }
    //       }
    //    }
    // }
    // vector<bool> camelMatch(vector<string>& queries, string pattern) {
    //     Trie* root=new Trie('-');
    //     int n=queries.size();
    //     for(int i=0;i<queries.size();i++){
    //         root->insertHelp(root,queries[i],0,i);
    //     }  
    //     vector<bool>ans(n,0);
    //     solve(root,pattern,0,ans);
    //     return ans;
    // } 



    // bool solve(string &s,string &p,int i,int j){//O(max(s,p))
    //     if(j>=p.size()){
    //         bool islower=true;
    //         for(int k=i;k<s.size();k++){
    //             if(s[k]>='A'&&s[k]<='Z'){
    //                 islower=false;
    //                 break;
    //             }
    //         }
    //         return islower;
    //     }
    //     if(i>=s.size()) return false;

    //       if(s[i]==p[j]){
    //         return solve(s,p,i+1,j+1);
    //       }
    //       else{
    //         if(islower(s[i]))
    //         return solve(s,p,i+1,j);
    //         else
    //         return false;
    //       }
    // }
    // vector<bool> camelMatch(vector<string>& queries, string pattern) {
    //    vector<bool>ans(queries.size(),0);
    //    for(int p=0;p<queries.size();p++){//O(n*n)
    //       int i=0;
    //       int j=0;
    //       ans[p]=solve(queries[p],pattern,i,j);
    //    }
    //    return ans;
    // } 



    bool solve(string &s,string &p,int i,int j){//O(max(s,p))
        while(i<s.size()){
            if(j<p.size()&&s[i]==p[j]){
                i++;j++;
            }
            else{
                if(isupper(s[i]))
                return false;
                else
                i++;
            }
        }
        return j==p.size();
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
       vector<bool>ans(queries.size(),0);
       for(int p=0;p<queries.size();p++){//O(n*n)
          int i=0;
          int j=0;
          ans[p]=solve(queries[p],pattern,i,j);
       }
       return ans;
    } 
};