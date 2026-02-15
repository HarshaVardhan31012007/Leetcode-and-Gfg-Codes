class Solution {
public:
    class Trie{
        public:
        int bit;
        int cnt;
        Trie* children[2];
        bool isterminal;
        
        Trie(int val){
            this->bit=val;
            this->cnt=0;
            this->children[0]=NULL;
            this->children[1]=NULL;
            this->isterminal=false;
        }
      
        void insert(Trie* root,int x){
            for(int i=31;i>=0;i--){
                int bit=(x>>i)&1;
                if(root->children[bit]==NULL)
                root->children[bit]=new Trie(bit);
                root->children[bit]->cnt++;
                root=root->children[bit];
            }
            root->isterminal=true;
        }  
        
        int getMax(Trie* root,int x){
            int ans=0;
            for(int i=31;i>=0;i--){
                int bit=(x>>i)&1;
                if(root->children[1-bit]&&root->children[1-bit]->cnt>0){
                  root=root->children[1-bit];
                  ans=ans|(1<<i);
                }
                else if(root->children[bit]&&root->children[bit]->cnt>0){
                    root=root->children[bit];
                }
                else
                break;
            }
            return ans;
        }
        void erase(Trie* root,int x){
            for(int i=31;i>=0;i--){
                int bit=(x>>i)&1;
                if(root->children[bit]&&root->children[bit]->cnt>0){
                    root->children[bit]->cnt--;
                    root=root->children[bit];
                }
            }
            root->isterminal=false;
        }
    };
    int maxXor(vector<int>& nums, int k) {
        deque<int>dq1;//mini
        deque<int>dq2;//maxi
        int n=nums.size();
        int prefix=0;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            prefix=prefix^nums[i];
            v[i]=prefix;
        }
        int i=0;int ans=0;
        Trie* root=new Trie('-');
        prefix=0;
        root->insert(root,0);
        for(int j=0;j<n;j++){
           prefix=prefix^nums[j];
           while(!dq1.empty()&&nums[j]<=nums[dq1.back()]){
               dq1.pop_back();
           }
           while(!dq2.empty()&&nums[j]>=nums[dq2.back()]){
               dq2.pop_back();
           }
           dq1.push_back(j);
           dq2.push_back(j);
           while((nums[dq2.front()]-nums[dq1.front()])>k){
              if(!dq1.empty()&&dq1.front()==i) dq1.pop_front();
              if(!dq2.empty()&&dq2.front()==i) dq2.pop_front();
              if(i==0)
              root->erase(root,0);
              else
              root->erase(root,v[i-1]);
              i++;
           }
           ans=max(ans,root->getMax(root,prefix));
           root->insert(root,prefix);
        }
        return ans;
    }
};