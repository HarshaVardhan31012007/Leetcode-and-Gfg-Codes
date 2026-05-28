class Solution {
public:
    class Trie{
        public:
        Trie* children[26];
        int index;
        Trie(){
            this->index=-1;
            for(int i=0;i<26;i++)
            this->children[i]=NULL;
        }
    };
    void assign(Trie* root,string &str,int index,vector<string>& wordsContainer){
        if(root->index==-1||(int)str.length()<wordsContainer[root->index].length()){
            root->index=index;
        }
    }
    void insert(Trie* root,string &str,int index,int maxi,vector<string>& wordsContainer){
        for(int i=(int)str.length()-1;i>=0&&maxi>=0;i--,maxi--){
            if(root->children[str[i]-'a']==NULL)
            root->children[str[i]-'a']=new Trie();
            root=root->children[str[i]-'a'];
            assign(root,str,index,wordsContainer);
        }
    }
    int search(Trie* root,string &each){
        for(int i=(int)each.length()-1;i>=0;i--){
            if(root->children[each[i]-'a']==NULL) break;
            root=root->children[each[i]-'a'];
        }
        return root->index;
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie* root=new Trie();
        int maxi=INT_MIN;
        for(int i=0;i<wordsQuery.size();i++){
            maxi=max(maxi,(int)wordsQuery[i].length());
        }
        for(int i=0;i<wordsContainer.size();i++){
            assign(root,wordsContainer[i],i,wordsContainer);
            insert(root,wordsContainer[i],i,maxi,wordsContainer);
        }
        vector<int>ans;
        for(int i=0;i<wordsQuery.size();i++){
            ans.push_back(search(root,wordsQuery[i]));
        }
        return ans;
    }
};