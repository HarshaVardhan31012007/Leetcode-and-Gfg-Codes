class Solution {
public:
    class Trie{
        public:
        Trie* children[26];
        int index;
        Trie(){
            for(int i=0;i<26;i++){
                this->children[i]=NULL;
            }
            this->index=-1;
        }
    };
    void insert(Trie* root,string &str,int idx){
        int n=str.length();
        for(int i=0;i<n;i++){
            if(root->children[str[i]-'a']==NULL)
            root->children[str[i]-'a']=new Trie();
            root=root->children[str[i]-'a'];
        }
        root->index=idx;
    }
    void traverse(Trie* root,int &ansIndex,vector<string>&words){
        for(int i=0;i<26;i++){
            if(!root->children[i]||root->children[i]->index==-1) continue;
            traverse(root->children[i],ansIndex,words);
        }
        if(root->index!=-1){
           if(ansIndex==-1||words[root->index].length()>words[ansIndex].length())
           ansIndex=root->index;
        }
    }
    string longestWord(vector<string>& words) {
        // unordered_set<string>st(words.begin(),words.end());
        // string ans="";
        // for(auto &each:words){
        //     string temp="";
        //     for(auto &ch:each){
        //         temp+=ch;
        //         if(!st.count(temp)) break;
        //         if(temp.length()>ans.length()){
        //             ans=temp;
        //         }
        //         else if(temp.length()==ans.length()&&temp<ans){
        //             ans=temp;
        //         }
        //     }
        // }
        // return ans;
        Trie* root=new Trie();
        for(int i=0;i<words.size();i++){
           insert(root,words[i],i);
        }
        int ansIndex=-1;
        traverse(root,ansIndex,words);
        return (ansIndex==-1?"":words[ansIndex]);
    }
};