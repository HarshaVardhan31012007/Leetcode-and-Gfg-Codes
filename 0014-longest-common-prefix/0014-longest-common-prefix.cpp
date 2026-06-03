class Solution {
public:
    class Trie{
        public:
        char data;
        Trie* children[26];
        bool isterminal;
        Trie(char val){
            this->data=val;
            for(int i=0;i<26;i++)
            this->children[i]=NULL;
            this->isterminal=false;
        }
    };
    void insert(Trie* root,string &each){
        for(int i=0;i<each.length();i++){
            if(root->children[each[i]-'a']==NULL){
                root->children[each[i]-'a']=new Trie(each[i]);
            }
            root=root->children[each[i]-'a'];
        }
        root->isterminal=true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        Trie* root=new Trie('-');
        for(auto &each:strs){
           insert(root,each);
        }
        bool flag=true;
        Trie* root1=root;
        string ans="";
        if(root->isterminal) return ans;
        while(1){
            Trie* temp=NULL;
            for(int i=0;i<26;i++){
                 if(temp==NULL&&root1->children[i])
                 temp=root1->children[i];
                 else if(temp&&root1->children[i]){
                    flag=false;
                    break;
                 }
            }
            if(temp==NULL) break;
            if(flag){
                ans+=temp->data;
                root1=temp;
                if(temp->isterminal) return ans;
            }
            else{
                break;
            }
        }
        return ans;
    }
};