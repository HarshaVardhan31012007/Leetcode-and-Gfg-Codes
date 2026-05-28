class Solution {
public:
    class Trie{
        public:
        Trie* children[26];
        int index;
        int length;
        Trie(){
            this->index=-1;
            this->length=-1;
            for(int i=0;i<26;i++)
            this->children[i]=NULL;
        }
    };
    void assign(Trie* root,string &str,int index){
        if(root->index==-1){
            root->index=index;
            root->length=(int)str.length();
        }
        else if((int)str.length()<root->length){
            root->length=(int)str.length();
            root->index=index;
        }
        else if((int)str.length()==root->length&&index<root->index){
            root->index=index;
        }
    }
    void insert(Trie* root,string &str,int index,int maxi){
        for(int i=(int)str.length()-1;i>=0&&maxi>=0;i--,maxi--){
            if(root->children[str[i]-'a']==NULL)
            root->children[str[i]-'a']=new Trie();
            root=root->children[str[i]-'a'];
            assign(root,str,index);
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
            assign(root,wordsContainer[i],i);
            insert(root,wordsContainer[i],i,maxi);
        }
        vector<int>ans;
        for(int i=0;i<wordsQuery.size();i++){
            ans.push_back(search(root,wordsQuery[i]));
        }
        return ans;
    }
};