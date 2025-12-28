// User function Template for C++

class Solution {
  public:
     class Trie{
         public:
         char data;
         Trie* children[26];
         bool isterminal;
         string word;
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
      void solve(Trie* root,vector<string>&temp){
          if(root->isterminal)
          temp.push_back(root->word);
          for(int i=0;i<26;i++){
              if(root->children[i]){
                  solve(root->children[i],temp);
              }
          }
      }
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        Trie* root=new Trie('-');
        for(int i=0;i<n;i++){
            Trie* curr=root;string each=contact[i];
            for(int i=0;i<each.length();i++){
              if(curr->children[each[i]-'a']==NULL)
              curr->children[each[i]-'a']=new Trie(each[i]);
              curr=curr->children[each[i]-'a'];
            }
            curr->isterminal=true;
            curr->word=each;
        }
        vector<vector<string>>ans;
        string each="";
        for(int i=0;i<s.length();i++){
            each+=s[i];
            vector<string>temp;
            Trie* curr=root;
            bool flag=1;
            for(int i=0;i<each.length();i++){
              if(curr->children[each[i]-'a']==NULL){
                  flag=0;
                  break;
              }
              curr=curr->children[each[i]-'a'];
            }
            if(!flag){
                temp={"0"};
            }
            else{
                solve(curr,temp);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};