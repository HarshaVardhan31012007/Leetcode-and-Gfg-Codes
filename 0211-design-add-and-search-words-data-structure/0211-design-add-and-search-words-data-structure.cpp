class WordDictionary {
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
    bool searchHelp(TrieNode* root,string &word,int i){
        if(i>=word.length()) return root->isterminal;
        if(word[i]=='.'){
            bool ans=false;
            for(auto &each:root->children){
               ans=ans||searchHelp(each.second,word,i+1);
            }
            return ans;
        }
        else{
            if(root->children.find(word[i])==root->children.end())
            return false;
            return searchHelp(root->children[word[i]],word,i+1);
        }
    }
    TrieNode* root;
    WordDictionary() {
        root=new TrieNode('-');
    }
    
    void addWord(string word) {
        insertHelp(root,word,0);
    }
    
    bool search(string word) {
        return searchHelp(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */