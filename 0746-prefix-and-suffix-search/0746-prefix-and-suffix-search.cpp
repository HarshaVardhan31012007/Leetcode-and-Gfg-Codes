//method 1 using maps
// class WordFilter {
// public:
// unordered_map<string,int>mpp;
//     WordFilter(vector<string>& words) {
//         for(int i=0;i<words.size();i++){
//             string word=words[i];
//             for(int j=1;j<=word.size();j++){
//                 string pre=word.substr(0,j);
//                 for(int k=0;k<word.size();k++){
//                     string suf=word.substr(k);
//                     mpp[pre+'{'+suf]=i;
//                 }
//             }
//         }
//     }
    
//     int f(string pref, string suff) {
//        if(mpp.find(pref+'{'+suff)!=mpp.end())
//        return mpp[pref+'{'+suff];
//        return -1;
//     }
// };


//method 2 using trieNode
class TrieNode{
    public:
    char data;
    unordered_map<char,TrieNode*>children;
   // bool isterminal;
    int index;
    TrieNode(char val){
        this->data=val;
       // this->isterminal=false;
        this->index=-1;
    }
};
void insert(TrieNode *root,string k,int i,int index){
  if(i>=k.length()){
   // root->isterminal=true;
    return;
  }
  if(root->children.find(k[i])==root->children.end()){
    root->children[k[i]]=new TrieNode(k[i]);
  }
  root->children[k[i]]->index=index;
  insert(root->children[k[i]],k,i+1,index);
}
int search(TrieNode *root,string k,int i){
    if(i>=k.length()){
       return root->index;
    }
    if(root->children.find(k[i])!=root->children.end())
    return search(root->children[k[i]],k,i+1);
    return -1;
}
class WordFilter {
public:
    TrieNode *root;
    WordFilter(vector<string>& words) {
        root=new TrieNode('-');

        //MLE
        for(int i=0;i<words.size();i++){
            string word=words[i];
            string pre="";
            for(int j=0;j<word.size();j++){
                pre=pre+word[j];
                string suf="";
                for(int k=word.size()-1;k>=0;k--){
                    suf=word[k]+suf;
                    insert(root,suf+'{'+pre,0,i);
                }
            }
        }


        // for(int i=0;i<words.size();i++){
        //     string word=words[i];
        //     string suf="";
        //         for(int k=word.size()-1;k>=0;k--){
        //             suf=word[k]+suf;
        //             insert(root,suf+'{'+word,0,i);
        //         }
        // }
    }
    
    int f(string pref, string suff) {
         return search(root,suff+'{'+pref,0);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */