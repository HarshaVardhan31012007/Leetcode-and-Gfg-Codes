class Trie {
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
    bool searchHelp(TrieNode* root,string word,int i){
          if(i>=word.length()) return root->isterminal;
          if(root->children.find(word[i])==root->children.end())
          return false;
          return searchHelp(root->children[word[i]],word,i+1);
    }
    bool searchPrefix(TrieNode* root,string word,int i){
          if(i>=word.length()) return true;
          if(root->children.find(word[i])==root->children.end())
          return false;
          return searchPrefix(root->children[word[i]],word,i+1);
    }
    TrieNode* root;
    Trie() {
        root=new TrieNode('-');
    }
    
    void insert(string word) {
        insertHelp(root,word,0);
    }
    
    bool search(string word) {
        return searchHelp(root,word,0);
    }
    
    bool startsWith(string prefix) {
        return searchPrefix(root,prefix,0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */