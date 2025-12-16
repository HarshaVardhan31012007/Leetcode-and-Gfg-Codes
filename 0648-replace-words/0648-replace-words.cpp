class Solution {
public:
    // string replaceWords(vector<string>& dictionary, string sentence) {
    //     unordered_map<string,bool>mpp;
    //     for(auto &each:dictionary){
    //         mpp[each]=1;
    //     }
    //     string ans="";
    //     for(int i=0;i<sentence.length();i++){
    //         string temp="";
    //         bool flag=1;
    //         while(i<sentence.length()&&sentence[i]!=' '){
    //             temp+=sentence[i++];
    //             if(flag&&mpp.count(temp)){
    //                 if(ans.empty())
    //                 ans+=temp;
    //                 else
    //                 ans+=" "+temp;
    //                 flag=0;
    //             }
    //         }
    //         if(flag){
    //             if(ans.empty())
    //             ans+=temp;
    //             else
    //             ans+=" "+temp;
    //         }
    //     }
    //     return ans;
    // }

    class Trie{
        public:

        char data;
        unordered_map<char,Trie*>children;
        bool isterminal;
        
        Trie(char val){
            this->data=val;
            this->isterminal=false;
        } 

        void insertHelp(Trie* root,string word,int i){
            if(i>=word.length()){
                root->isterminal=true;
                return;
            }
            if(root->children.find(word[i])==root->children.end())
            root->children[word[i]]=new Trie(word[i]);
            insertHelp(root->children[word[i]],word,i+1);
        }
        
        int searchHelp(Trie* root,string word,int i){
            if(root->isterminal) return i;
            if(i>=word.length()) return (root->isterminal?i:-1);
            if(root->children.find(word[i])==root->children.end())
            return -1;
            return searchHelp(root->children[word[i]],word,i+1);
        } 
    };



    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* root=new Trie('-');
        for(auto &each:dictionary){
            root->insertHelp(root,each,0);
        }
        string ans="";
        for(int i=0;i<sentence.length();i++){
            string temp="";
            while(i<sentence.length()&&sentence[i]!=' '){
                temp+=sentence[i++];
            }
            int idx=root->searchHelp(root,temp,0);
            if(ans.empty())
            ans+=temp.substr(0,idx);
            else
            ans+=" "+temp.substr(0,idx);
        }
        return ans;
    }
};