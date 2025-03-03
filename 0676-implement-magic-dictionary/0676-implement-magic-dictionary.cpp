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
        if(root->children.count(k[i])==0)
        root->children[k[i]]=new TrieNode(k[i]);
        insertHelp(root->children[k[i]],k,i+1);
    }

    // bool searchW(TrieNode *root,string k,int i=0,int change=0){
    //       if(i>=k.length()){
    //         return root->isterminal&&change==1;
    //       }
    //       bool mismatched=false;
    //       for(auto &[val,node]:root->children){
    //       if(val!=k[i]&&change==0)
    //       mismatched=mismatched||searchW(node,k,i+1,change+1);
    //       else if(val==k[i])
    //       mismatched=mismatched||searchW(node,k,i+1,change);
    //       if(mismatched==true) return true;
    //       }
    //       return mismatched;
    // }


    //  bool searchW(TrieNode *root,string k,int i=0,int change=0){
    //       if(i>=k.length()){
    //         return root->isterminal&&change==1;
    //       }
    //       if(change>1) return false;
    //       bool mismatched=false;
    //       for(auto &[val,node]:root->children){
    //       if(val!=k[i])
    //       mismatched=mismatched||searchW(node,k,i+1,change+1);
    //       else
    //       mismatched=mismatched||searchW(node,k,i+1,change);
    //       if(mismatched==true) return true;
    //       }
    //       return mismatched;
    // }

        bool searchW(TrieNode *root,string k,int i=0,int change=0){
          if(i>=k.length()){
            return root->isterminal&&change==1;
          }
          if(change>1) return false;
          for(auto &[val,node]:root->children){
          if(val!=k[i]&&searchW(node,k,i+1,change+1)) return true;
          else if(val==k[i]&&searchW(node,k,i+1,change)) return true;
          }
          return false;
    }
class MagicDictionary {
public:
    TrieNode *root;
    MagicDictionary() {
        root=new TrieNode('-');
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto each:dictionary)
        insertHelp(root,each);
    }
    
    bool search(string searchWord) {
        return searchW(root,searchWord);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */