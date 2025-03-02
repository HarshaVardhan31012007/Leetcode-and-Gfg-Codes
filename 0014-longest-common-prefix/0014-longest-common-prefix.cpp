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
    void insertHelp(TrieNode *root,string k){
        if(k.length()==0){
            root->isterminal=true;
            return;
        }
        char ch=k[0];
        TrieNode *child;
        if(root->children.count(ch)==0){
            child=new TrieNode(ch);
            root->children[ch]=child;
        }
        else{
            child=root->children[ch];
        }
        insertHelp(child,k.substr(1));
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

class Solution {
public:
    void func(TrieNode *root,string &k){
        if(root->children.size()>1||root->isterminal){
            return;
        }
        if(root->children.empty()) return;
        k=k+root->children.begin()->first;
        func(root->children.begin()->second,k);
    }
    string longestCommonPrefix(vector<string>& strs) {
        // string output="";int mini=INT_MAX;
        // for(int i=0;i<strs.size();i++){
        //     int p=strs[i].size();
        //     mini=min(mini,p);
        // }
        // for(int i=0;i<mini;i++){
        //     bool issame=true;
        //     char ch=strs[0][i];
        //     for(int j=1;j<strs.size();j++){
        //         if(strs[j][i]!=ch){
        //         issame=false;
        //         break;
        //         }
        //     }
        //     if(issame)
        //     output+=ch;
        //     else
        //     break;
        // }
        // return output;

    
        // string output="";
        // for(int i=0; ;i++){
        //     bool issame=true;
        //     if(i>=strs[0].size()) break;
        //     char ch=strs[0][i];
        //     for(int j=1;j<strs.size();j++){
        //         if(i>=strs[j].size()){
        //             issame=false;
        //             break;
        //         }
        //         if(strs[j][i]!=ch){
        //         issame=false;
        //         break;
        //         }
        //     }
        //     if(issame)
        //     output+=ch;
        //     else
        //     break;
        // }
        // return output;



        // string output="";
        // int i=0;
        // while(true){
        //     char ch=0;
        //     for(int j=0;j<strs.size();j++){
        //         if(i>=strs[j].size()){
        //             ch=0;
        //             break;
        //         }
        //         if(ch==0){
        //             ch=strs[j][i];
        //         }
        //         else if(strs[j][i]!=ch){
        //         ch=0;
        //         break;
        //         }
        //     }
        //     if(ch==0)
        //     break;
        //     output+=ch;
        //     i++;
        // }
        // return output;


        TrieNode *root=new TrieNode('-');

        for(int i=0;i<strs.size();i++){
            insertHelp(root,strs[i]);
        }
        
        string output="";
        func(root,output);
        return output;
    }
};