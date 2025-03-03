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
    // bool searchWord(TrieNode *root,string k){
    //     if(k.length()==0){
    //         return root->isterminal==true;
    //     }
    //     char ch=k[0];
    //     if(root->children.count(ch)==0){
    //         return false;
    //     }
    //     return searchWord(root->children[ch],k.substr(1));
    // }
    // bool searchPrefix(TrieNode *root,string k){
    //     if(k.length()==0){
    //         return true;
    //     }
    //     char ch=k[0];
    //     if(root->children.count(ch)==0){
    //         return false;
    //     }
    //     return searchPrefix(root->children[ch],k.substr(1));
    // }

    bool searchW(TrieNode *root,string k,int i=0){
        if(i>=k.length()){
            return root->isterminal==true;
        }
        char ch=k[i];
        if(root->children.count(ch)==0&&ch!='.'){
            return false;
        }
        TrieNode *child;
        if(root->children.count(ch)==1){
                child=root->children[ch];
        }
        else{
                bool fans=0;
                for(auto each:root->children){
                child=each.second;
                bool ans=searchW(child,k,i+1);
                if(ans==1){
                fans=1;
                 break;
                }
                }
             return fans;
        }
        return searchW(child,k,i+1);
    }
class WordDictionary {
public:
   TrieNode *root;
    WordDictionary() {
        root=new TrieNode('-');
    }
    
    void addWord(string word) {
        insertHelp(root,word);
    }
    
    bool search(string word) {
        return searchW(root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */