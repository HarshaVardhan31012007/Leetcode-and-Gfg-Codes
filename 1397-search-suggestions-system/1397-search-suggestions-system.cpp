// class TrieNode{
//         public:
//         char data;
//         unordered_map<char,TrieNode*>children;
//         bool isterminal;
//         TrieNode(char val){
//             this->data=val;
//             isterminal=false;
//         }
//     };
//     void insertHelp(TrieNode *root,string k,int i=0){
//         if(i>=k.length()){
//             root->isterminal=true;
//             return;
//         }
//         if(root->children.count(k[i])==0)
//         root->children[k[i]]=new TrieNode(k[i]);
//         insertHelp(root->children[k[i]],k,i+1);
//     }
    
// class Solution {
// public:
//     void store(TrieNode *root,vector<string>&tem,string k){
//         if(root->isterminal){
//             tem.push_back(k);
//             sort(tem.begin(),tem.end());
//             if(tem.size()>3)
//             tem.resize(3);
//         }
//         for(auto &each:root->children){
//             k.push_back(each.first);
//             store(each.second,tem,k);
//             k.pop_back();
//         }
//     }
//     void findSuggestions(TrieNode *root,vector<string>&tem,string &k,int i=0){
//         if(i>=k.size()){
//             string temp=k;
//             store(root,tem,temp);
//             return;
//         }
//         if(root->children.count(k[i])==1)
//         findSuggestions(root->children[k[i]],tem,k,i+1);
//     }
//     vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
//         TrieNode *root=new TrieNode('-');
//         for(int i=0;i<products.size();i++){
//             insertHelp(root,products[i]);
//         }
//         vector<vector<string>>ans;
//         string temp="";
//         for(auto &each:searchWord){
//             vector<string>tem;
//             temp.push_back(each);
//             findSuggestions(root,tem,temp);
//             // sort(tem.begin(),tem.end());
//             // if(tem.size()>3)
//             // tem.resize(3);
//             ans.push_back(tem);
//         }
//         return ans;
//     }
// };


class TrieNode{
        public:
        char data;
        unordered_map<char,TrieNode*>children;
        bool isterminal;
        string word;
        TrieNode(char val){
            this->word="";
            this->data=val;
            isterminal=false;
        }
    };
    void insertHelp(TrieNode *root,string k,int i=0){
        if(i>=k.length()){
            root->isterminal=true;
            root->word=k;
            return;
        }
        if(root->children.count(k[i])==0)
        root->children[k[i]]=new TrieNode(k[i]);
        insertHelp(root->children[k[i]],k,i+1);
    }
    
class Solution {
public:
    void store(TrieNode *root,vector<string>&tem){
        if(root->isterminal){
            tem.push_back(root->word);
            sort(tem.begin(),tem.end());
            if(tem.size()>3)
            tem.resize(3);
        }
        for(auto &each:root->children){
            //k.push_back(each.first);
            store(each.second,tem);
            //k.pop_back();
        }
    }
    void findSuggestions(TrieNode *root,vector<string>&tem,string &k,int i=0){
        if(i>=k.size()){
            store(root,tem);
            return;
        }
        if(root->children.count(k[i])==1)
        findSuggestions(root->children[k[i]],tem,k,i+1);
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode *root=new TrieNode('-');
        for(int i=0;i<products.size();i++){
            insertHelp(root,products[i]);
        }
        vector<vector<string>>ans;
        string temp="";
        for(auto &each:searchWord){
            vector<string>tem;
            temp.push_back(each);
            findSuggestions(root,tem,temp);
            // sort(tem.begin(),tem.end());
            // if(tem.size()>3)
            // tem.resize(3);
            ans.push_back(tem);
        }
        return ans;
    }
};