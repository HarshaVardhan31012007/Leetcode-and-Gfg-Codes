class Solution {
    public:
    class Trie{
        public:
        char data;
        Trie* children[26];
        bool isterminal;
        Trie(char val){
            this->data=val;
            this->isterminal=false;
            for(int i=0;i<26;i++){
                this->children[i]=NULL;
            }
        }
    };
    void insert(Trie* root,string &s,int i){
        if(i>=s.length()){
             root->isterminal=true;
             return;
        }
        if(root->children[s[i]-'a']==NULL)
        root->children[s[i]-'a']=new Trie(s[i]);
        insert(root->children[s[i]-'a'],s,i+1);
    }
    void solve(Trie* root,string &temp,string &ans){
        bool flag=1;
        for(int i=0;i<26;i++){
            if(root->children[i]&&root->children[i]->isterminal){
                temp.push_back(i+'a');
                solve(root->children[i],temp,ans);
                temp.pop_back();
                flag=0;
            }
        }
        if(flag){
            if(ans=="")
            ans=temp;
            else if(temp.length()>ans.length())
            ans=temp;
        }
    }
    string longestValidWord(vector<string>& words) {
        string ans="";
        string temp="";
        Trie* root=new Trie('-');
        for(auto &each:words){
            insert(root,each,0);
        }
        solve(root,temp,ans);
        return ans;
    }
};
