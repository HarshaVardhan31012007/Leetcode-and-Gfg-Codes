// User function Template for C++

class Solution {
  public:
    class Trie{
        public:
        int bit;
        Trie* children[2];
        bool isterminal;
        
        Trie(int val){
            this->bit=val;
            this->children[0]=NULL;
            this->children[1]=NULL;
            this->isterminal=false;
        }
      
        void insert(Trie* root,int x){
            for(int i=31;i>=0;i--){
                int bit=(x>>i)&1;
                if(root->children[bit]==NULL)
                root->children[bit]=new Trie(bit);
                root=root->children[bit];
            }
            root->isterminal=true;
        }  
        
        int getMax(Trie* root,int x){
            int ans=0;
            for(int i=31;i>=0;i--){
                int bit=(x>>i)&1;
                if(root->children[1-bit]){
                  root=root->children[1-bit];
                  ans=ans|(1<<i);
                }
                else{
                    root=root->children[bit];
                }
            }
            return ans;
        }
    };
    int maxSubarrayXOR(int N, int arr[]) {
        int prefix=0;
        Trie * root=new Trie('-');
        int ans=0;
        for(int i=0;i<N;i++){
           prefix=prefix^arr[i];
           root->insert(root,prefix);
           ans=max(ans,root->getMax(root,prefix));
           ans=max(ans,prefix);
        }
        return ans;
    }
};