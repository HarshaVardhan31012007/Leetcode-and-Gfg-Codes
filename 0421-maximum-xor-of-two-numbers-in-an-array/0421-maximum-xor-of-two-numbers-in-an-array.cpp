class Trie{
    public:
    char data;
    Trie* children[2];
    bool isterminal;

    Trie(char val){
        this->data=val;
        this->children[0]=NULL;
        this->children[1]=NULL;
        this->isterminal=false;
    }

    void insert(Trie* root,int num){
        for(int i=31;i>=0;i--){
            int bit=((num>>i)&1);
            if(root->children[bit]==NULL)
            root->children[bit]=new Trie(bit+'0');
            root=root->children[bit];
        }
        root->isterminal=true;
    }

    int getMax(Trie* root,int x){
        int ans=0;
          for(int i=31;i>=0;i--){
              int bit=((x>>i)&1);
              if(root->children[1-bit]){
                   ans=ans|(1<<i);
                   root=root->children[1-bit];
              }
              else{
                  root=root->children[bit];
              }
          }
          return ans;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* root=new Trie('-');
        int maxi=0;
         for(auto &each:nums){
            root->insert(root,each);
            maxi=max(maxi,root->getMax(root,each));
         }
         return maxi;
    }
};