class Solution {
public:
     class TrieNode{
       public:
       char data;
       unordered_map<char,TrieNode*>children;
       bool isterminal;
       string word;
       TrieNode(char val){
          this->data=val;
          this->isterminal=false;
       }
    };
    void insertHelp(TrieNode* root,string word,int i){
        if(i>=word.length()){
            root->isterminal=true;
            root->word=word;
            return;
        }
        if(root->children.find(word[i])==root->children.end())
        root->children[word[i]]=new TrieNode(word[i]);
        insertHelp(root->children[word[i]],word,i+1);
    }
    void store(TrieNode* root,vector<string>&temp){
        if(root->isterminal){
            temp.push_back(root->word);
            sort(temp.begin(),temp.end());
            if(temp.size()>3)
            temp.pop_back();
        }
        for(auto &each:root->children){
            store(each.second,temp);
        }
    }
    void findSuggestions(TrieNode* root,string &prefix,int i,vector<string>&temp){
        if(i>=prefix.length()){
            store(root,temp);
            return;
        }
        if(root->children.find(prefix[i])==root->children.end())
        return;
        findSuggestions(root->children[prefix[i]],prefix,i+1,temp);
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* root=new TrieNode('-');
        for(auto &product:products){
            insertHelp(root,product,0);
        }
        vector<vector<string>>ans;
        string prefix="";
        for(auto &each:searchWord){
            prefix+=each;
            vector<string>temp;
            findSuggestions(root,prefix,0,temp);
            ans.push_back(temp);
        }
        return ans;
    }
};