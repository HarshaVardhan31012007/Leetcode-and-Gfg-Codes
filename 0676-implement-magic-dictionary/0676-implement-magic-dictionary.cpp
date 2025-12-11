class MagicDictionary {
public:
     class TrieNode{
       public:
       char data;
       unordered_map<char,TrieNode*>children;
       bool isterminal;
       TrieNode(char val){
          this->data=val;
          this->isterminal=false;
       }
    };
    void insertHelp(TrieNode* root,string word,int i){
        if(i>=word.length()){
            root->isterminal=true;
            return;
        }
        if(root->children.find(word[i])==root->children.end())
        root->children[word[i]]=new TrieNode(word[i]);
        insertHelp(root->children[word[i]],word,i+1);
    }
    bool searchHelp(TrieNode* root,string &word,int i,bool change){
        if(i>=word.length()) return change&&root->isterminal;
        if(change){
           if(root->children.find(word[i])==root->children.end())
           return false;
           return searchHelp(root->children[word[i]],word,i+1,change);
        }
        bool ans=false;
        for(auto &each:root->children){
            if(each.first==word[i])
            ans=ans||searchHelp(each.second,word,i+1,change);//important remenber you have to go each.second for further checking and dont stay on root
            else
            ans=ans||searchHelp(each.second,word,i+1,true);
        }
        return ans;
    }
    TrieNode* root;
    MagicDictionary() {
         root=new TrieNode('-');
    }
    
    void buildDict(vector<string> dictionary) {
         for(auto &str:dictionary){
            insertHelp(root,str,0);
         }
    }
    
    bool search(string searchWord) {
         return searchHelp(root,searchWord,0,false);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */