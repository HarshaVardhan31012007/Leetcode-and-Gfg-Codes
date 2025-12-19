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
    void insert(Trie* root,string &s,int i,int &count){
        if(i>=s.length()){
             return;
        }
        if(root->children[s[i]-'a']==NULL)
        root->children[s[i]-'a']=new Trie(s[i]);
        if(!root->children[s[i]-'a']->isterminal){
            root->isterminal=true;
            count++;
        }
        insert(root->children[s[i]-'a'],s,i+1,count);
    }
    int countSubs(string& s) {
        // unordered_set<string>st;
        // for(int i=0;i<s.length();i++){
        //     string temp="";
        //     for(int j=i;j<s.length();j++){
        //         temp+=s[j];
        //         st.insert(temp);
        //     }
        // }
        // return st.size();
        
        
        Trie* root=new Trie('-');
        int count=0;
        for(int i=0;i<s.length();i++){
            string temp=s.substr(i);
            insert(root,temp,0,count);
        }
        return count;
    }
};