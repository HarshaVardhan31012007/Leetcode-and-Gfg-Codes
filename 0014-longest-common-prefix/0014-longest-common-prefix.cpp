class Solution {
public:
    // string longestCommonPrefix(vector<string>& strs) {
    //     int i=0;
    //     string ans="";
    //     while(1){
    //         char ch=0;
    //         for(int j=0;j<strs.size();j++){
    //             if(i>=strs[j].length()) return ans;
    //             if(ch==0)
    //             ch=strs[j][i];
    //             else{
    //                 if(ch!=strs[j][i]) return ans;
    //             }
    //         }
    //         ans+=strs[0][i];
    //         i++;
    //     }
    //     return "";
    // }



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
    string longestCommonPrefix(vector<string>& strs) {
       TrieNode* root=new TrieNode('-');
       for(auto &str:strs){
          insertHelp(root,str,0);
       }
       string ans="";
       while(root->children.size()==1){
           if(root->isterminal) return ans;//like ["","b"] ans is "" and ["a","ab"]
           auto it=root->children.begin();
           ans+=it->first;
           root=it->second;
       }
       return ans;
    }
};