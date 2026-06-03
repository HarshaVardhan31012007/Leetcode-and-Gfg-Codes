class Solution {
public:
    class Trie{
        public:
        Trie* children[26];
        bool isterminal;
        int size=0;
        int firstNodeidx;
        Trie(){
            for(int i=0;i<26;i++)
            this->children[i]=NULL;
            this->isterminal=false;
            this->firstNodeidx=-1;
            this->size=0;
        }
    };
    void insert(Trie* root,string &each){
        for(int i=0;i<each.length();i++){
            if(root->children[each[i]-'a']==NULL){
                root->children[each[i]-'a']=new Trie();
                root->size++;
                if(root->firstNodeidx==-1){
                    root->firstNodeidx=(each[i]-'a');
                }
            }
            root=root->children[each[i]-'a'];
        }
        root->isterminal=true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        Trie* root=new Trie();
        for(auto &each:strs){
           insert(root,each);
        }
        string ans="";
        while(root->size==1){
            if(root->isterminal) return ans;
            ans+=(root->firstNodeidx+'a');
            root=root->children[root->firstNodeidx];
        }
        return ans;
    }
};