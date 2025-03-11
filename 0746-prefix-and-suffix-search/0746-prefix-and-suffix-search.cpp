// class TrieNode{
//         public:
//         char data;
//         unordered_map<char,TrieNode*>children;
//         bool isterminal;
//         int index;
//         TrieNode(char val){
//             this->index=-1;
//             this->data=val;
//             isterminal=false;
//         }
//     };
//     void insertHelp(TrieNode *root,string k,int j,int i=0){
//         if(i>=k.length()){
//             root->isterminal=true;
//             root->index=j;
//             return;
//         }
//         if(root->children.count(k[i])==0)
//         root->children[k[i]]=new TrieNode(k[i]);
//         insertHelp(root->children[k[i]],k,j,i+1);
//     }
//     bool issubstr(string p,string q){
//         if(p.size()>=q.size()&&p.substr(p.size()-q.size(),q.size())==q)
//         return 1;
//         return 0;
//     }
//     void func(TrieNode *root,string q,int j,int &ans){
//         if(j>=q.size()&&root->isterminal){
//             ans=max(ans,root->index);
//             if(q=="dj")
//             cout<<ans<<endl;
//             return;
//         }
//         if(j>=q.size()||(j>=1&&root->children.count(q[j])==0)) return;
//         for(auto &[val,child]:root->children){
//            if(val==q[j]){
//            func(child,q,j+1,ans);
//            func(child,q,0,ans);
//            }
//            else{
//            func(child,q,j,ans);
//            } 
//         }
//     }
//     void search(TrieNode *root,string p,string q,int i,int &ans){
//         if(i>=p.size()){
//             if(issubstr(p,q)&&root->isterminal){
//                 ans=max(ans,root->index);
//                 func(root,q,0,ans);
//             }
//             else{
//                 int j=0;
//                 func(root,q,0,ans);
//                 int k=0;
//                 int i=p.size()-1;
//                    for(int j=q.size()-1;j>=0;j--){
//                     if(i>=0){
//                     if(p[i]==q[j]){
//                        if(k==0)
//                        k=j+1;
//                        i--;
//                     }
//                     else{
//                         if(k!=0){
//                         k=0;
//                         if(p[p.size()-1]==q[j]){
//                            if(k==0)
//                            k=j+1;
//                            i=p.size()-2;
//                         }
//                         }
//                     }
//                     }

//                    }
//                    cout<<k<<" "<<ans<<endl;
//                  if(k!=0)
//                 func(root,q,k,ans);
//             }
//             return;
//         }
//         if(root->children.find(p[i])!=root->children.end())
//         search(root->children[p[i]],p,q,i+1,ans);
//     }
class WordFilter {
public:
unordered_map<string,int>mpp;
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            string word=words[i];
            for(int j=1;j<=word.size();j++){
                string pre=word.substr(0,j);
                for(int k=0;k<word.size();k++){
                    string suf=word.substr(k);
                    mpp[pre+'{'+suf]=i;
                }
            }
        }
    }
    
    int f(string pref, string suff) {
       if(mpp.find(pref+'{'+suff)!=mpp.end())
       return mpp[pref+'{'+suff];
       return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */