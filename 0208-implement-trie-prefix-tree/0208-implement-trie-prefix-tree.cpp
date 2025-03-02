class TrieNode{
        public:
        char data;
        unordered_map<char,TrieNode*>children;
        bool isterminal;
        TrieNode(char val){
            this->data=val;
            isterminal=false;
        }
    };
    // void insertHelp(TrieNode *root,string k){
    //     if(k.length()==0){
    //         root->isterminal=true;
    //         return;
    //     }
    //     char ch=k[0];
    //     TrieNode *child;
    //     if(root->children.count(ch)==0){
    //         child=new TrieNode(ch);
    //         root->children[ch]=child;
    //     }
    //     else{
    //         child=root->children[ch];
    //     }
    //     insertHelp(child,k.substr(1));
    // }
    void insertHelp(TrieNode *root,string k,int i=0){
        if(i>=k.length()){
            root->isterminal=true;
            return;
        }
        char ch=k[i];
        TrieNode *child;
        if(root->children.count(ch)==0){
            child=new TrieNode(ch);
            root->children[ch]=child;
        }
        else{
            child=root->children[ch];
        }
        insertHelp(child,k,i+1);
    }
    bool searchWord(TrieNode *root,string k){
        if(k.length()==0){
            return root->isterminal==true;
        }
        char ch=k[0];
        if(root->children.count(ch)==0){
            return false;
        }
        return searchWord(root->children[ch],k.substr(1));
    }
    bool searchPrefix(TrieNode *root,string k){
        if(k.length()==0){
            return true;
        }
        char ch=k[0];
        if(root->children.count(ch)==0){
            return false;
        }
        return searchPrefix(root->children[ch],k.substr(1));
    }


class Trie {
public:
    TrieNode *root;
    Trie() {
       root=new TrieNode(-1); 
    }
    
    void insert(string word) {
        insertHelp(root,word);
    }
    
    bool search(string word) {
        return searchWord(root,word);
    }
    
    bool startsWith(string prefix) {
        return searchPrefix(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */