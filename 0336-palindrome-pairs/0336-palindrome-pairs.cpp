// class Solution {
// public:
//   class Trie{
//         public:

//         char data;
//         Trie* children[26];
//         bool isterminal;
//         int stringNumber;
        
//         Trie(char val){
//             this->data=val;
//             this->isterminal=false;
//             for(int i=0;i<26;i++){
//                 this->children[i]=NULL;
//             }
//         } 

//         void insertHelp(Trie* root,string word,int i,int &stringNumber){
//             if(i>=word.length()){
//                 root->isterminal=true;
//                 root->stringNumber=stringNumber;
//                 return;
//             }
//             if(root->children[word[i]-'a']==NULL)
//             root->children[word[i]-'a']=new Trie(word[i]);
//             insertHelp(root->children[word[i]-'a'],word,i+1,stringNumber);
//         }
//         bool checkpalindrome(string &s,int i,int j){
//             while(i<j){
//                 if(s[i]==s[j]){
//                     i++;j--;
//                 }
//                 else
//                 return false;
//             }
//             return true;
//         }
//         void solve(Trie* root,int &idx,vector<vector<int>>&ans,string &temp){
//             if(root->isterminal&&idx!=root->stringNumber&&checkpalindrome(temp,0,temp.size()-1)){
//                  ans.push_back({idx,root->stringNumber});
//             }
//              for(int i=0;i<26;i++){
//                 if(root->children[i]!=NULL){
//                     temp.push_back(i+'a');
//                     solve(root->children[i],idx,ans,temp);
//                     temp.pop_back();
//                 }
//              } 
//         }
//         void search(Trie* root,string &s,int i,int &idx,vector<vector<int>>&ans){
//             if(i>=s.length()){
//                 string temp="";
//                 solve(root,idx,ans,temp);
//                 return;
//             }
//             if(root->isterminal){//no return // later some character may match
//             //root->isterminal is imp beacuase up to root is matched and if rest of gievn word matched then it can form palindrome
//                 if(checkpalindrome(s,i,s.length()-1)&&idx!=root->stringNumber)
//                 ans.push_back({idx,root->stringNumber});
//             }
//             if(root->children[s[i]-'a']!=NULL){
//                 search(root->children[s[i]-'a'],s,i+1,idx,ans);
//             }
//         }
//      };
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         Trie* root=new Trie('-');
//         for(int i=0;i<words.size();i++){
//             string word=words[i];
//             reverse(word.begin(),word.end());
//             root->insertHelp(root,word,0,i);
//         }
//         vector<vector<int>>ans;
//         for(int i=0;i<words.size();i++){
//             root->search(root,words[i],0,i,ans);
//         }
//         return ans;
//     }
// };





// class Solution {
// public:
//   class Trie{
//         public:

//         char data;
//         Trie* children[26];
//         int stringNumber;
        
//         Trie(char val){
//             this->data=val;
//             this->stringNumber=-1;
//             for(int i=0;i<26;i++){
//                 this->children[i]=NULL;
//             }
//         } 

//         void insertHelp(Trie* root,string word,int i,int &stringNumber){
//             if(i>=word.length()){
//                 root->stringNumber=stringNumber;
//                 return;
//             }
//             if(root->children[word[i]-'a']==NULL)
//             root->children[word[i]-'a']=new Trie(word[i]);
//             insertHelp(root->children[word[i]-'a'],word,i+1,stringNumber);
//         }
//         bool checkpalindrome(string &s,int i,int j){
//             while(i<j){
//                 if(s[i]==s[j]){
//                     i++;j--;
//                 }
//                 else
//                 return false;
//             }
//             return true;
//         }
//         void solve(Trie* root,int &idx,vector<vector<int>>&ans,string &temp){
//             if(root->stringNumber!=-1&&idx!=root->stringNumber&&checkpalindrome(temp,0,temp.size()-1)){
//                  ans.push_back({idx,root->stringNumber});
//             }
//              for(int i=0;i<26;i++){
//                 if(root->children[i]!=NULL){
//                     temp.push_back(i+'a');
//                     solve(root->children[i],idx,ans,temp);
//                     temp.pop_back();
//                 }
//              } 
//         }
//         void search(Trie* root,string &s,int &idx,vector<vector<int>>&ans){
//             Trie* curr=root;
//             for(int i=0;i<s.length();i++){
//                  if(curr->stringNumber!=-1){//check for isterminal
//                       if(idx!=curr->stringNumber&&checkpalindrome(s,i,s.length()-1)){
//                              ans.push_back({idx,curr->stringNumber});
//                       }
//                  }
//                  if(curr->children[s[i]-'a']!=NULL){
//                     curr=curr->children[s[i]-'a'];
//                  }
//                  else
//                  return;
//             }
//             //if we reach here that means all s characters are matched//we are searching for more possible words in trie that make palindorme
//             string temp="";
//             solve(curr,idx,ans,temp);
//         }
//      };
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         Trie* root=new Trie('-');
//         for(int i=0;i<words.size();i++){
//             string word=words[i];
//             reverse(word.begin(),word.end());
//             root->insertHelp(root,word,0,i);
//         }
//         vector<vector<int>>ans;
//         for(int i=0;i<words.size();i++){
//             root->search(root,words[i],i,ans);
//         }
//         return ans;
//     }
// };



class Solution {
public:
  class Trie{
        public:

        char data;
        Trie* children[26];
        int stringNumber;
        
        Trie(char val){
            this->data=val;
            this->stringNumber=-1;
            for(int i=0;i<26;i++){
                this->children[i]=NULL;
            }
        } 

        void insertHelp(Trie* root,string &word,int i,int &stringNumber){
            if(i>=word.length()){
                root->stringNumber=stringNumber;
                return;
            }
            if(root->children[word[i]-'a']==NULL)
            root->children[word[i]-'a']=new Trie(word[i]);
            insertHelp(root->children[word[i]-'a'],word,i+1,stringNumber);
        }
        bool checkpalindrome(string &s,int i,int j){
            while(i<j){
                if(s[i]==s[j]){
                    i++;j--;
                }
                else
                return false;
            }
            return true;
        }
        void solve(Trie* root,vector<int>&temp,string &temp1){
            if(root->stringNumber!=-1&&checkpalindrome(temp1,0,temp1.size()-1)){
                 temp.push_back(root->stringNumber);
            }
             for(int i=0;i<26;i++){
                if(root->children[i]!=NULL){
                    temp1.push_back(i+'a');
                    solve(root->children[i],temp,temp1);
                    temp1.pop_back();
                }
             } 
        }
        void search(Trie* root,string &s,vector<int>&temp){
            Trie* curr=root;
            for(int i=0;i<s.length();i++){
                 if(curr->stringNumber!=-1){//check for isterminal
                      if(checkpalindrome(s,i,s.length()-1)){
                             temp.push_back(curr->stringNumber);
                      }
                 }
                 if(curr->children[s[i]-'a']!=NULL){
                    curr=curr->children[s[i]-'a'];
                 }
                 else
                 return;
            }
            //if we reach here that means all s characters are matched//we are searching for more possible words in trie that make palindorme
            string temp1="";
            solve(curr,temp,temp1);
        }
     };
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie* root=new Trie('-');
        for(int i=0;i<words.size();i++){
            string word=words[i];
            reverse(word.begin(),word.end());
            root->insertHelp(root,word,0,i);
        }
        vector<vector<int>>ans;
        for(int i=0;i<words.size();i++){
            vector<int>temp;
            root->search(root,words[i],temp);
            for(auto &each:temp){
                if(each!=i)
                ans.push_back({i,each});
            }
        }
        return ans;
    }
};



// class Solution {
// public:
//   class Trie{
//         public:

//         char data;
//         Trie* children[26];
//         int stringNumber;
//         vector<int>pindices;
        
//         Trie(char val){
//             this->data=val;
//             this->stringNumber=-1;
//             for(int i=0;i<26;i++){
//                 this->children[i]=NULL;
//             }
//         } 
//          bool checkpalindrome(string &s,int i,int j){
//             while(i<j){
//                 if(s[i]!=s[j]){
//                     return false;
//                 }
//                 i++;j--;
//             }
//             return true;
//         }
//         void insertHelp(Trie* root,string &word,int i,int &stringNumber){
//             if(checkpalindrome(word,i,word.length()-1)){
//                 root->pindices.push_back(stringNumber);
//             }
//             if(i>=word.length()){
//                 root->stringNumber=stringNumber;
//                 return;
//             }
//             if(root->children[word[i]-'a']==NULL)
//             root->children[word[i]-'a']=new Trie(word[i]);
//             insertHelp(root->children[word[i]-'a'],word,i+1,stringNumber);
//         }
//         void search(Trie* root,string &s,vector<int>&temp,int &idx){
//             Trie* curr=root;
//             for(int i=0;i<s.length();i++){
//                  if(curr->stringNumber!=-1){//check for isterminal
//                       if(curr->stringNumber!=idx&&checkpalindrome(s,i,s.length()-1)){
//                              temp.push_back(curr->stringNumber);
//                       }
//                  }
//                  if(curr->children[s[i]-'a']!=NULL){
//                     curr=curr->children[s[i]-'a'];
//                  }
//                  else
//                  return;
//             }
//             //if we reach here that means all s characters are matched//we are searching for more possible words in trie that make palindorme
//             for(auto &each:curr->pindices){
//                 if(idx!=each)
//                 temp.push_back(each);
//             }
//         }
//      };
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         Trie* root=new Trie('-');
//         for(int i=0;i<words.size();i++){
//             string word=words[i];
//             reverse(word.begin(),word.end());
//             root->insertHelp(root,word,0,i);
//         }
//         vector<vector<int>>ans;
//         for(int i=0;i<words.size();i++){
//             vector<int>temp;
//             root->search(root,words[i],temp,i);
//             for(auto &each:temp){
//                 ans.push_back({i,each});
//             }
//         }
//         return ans;
//     }
// };