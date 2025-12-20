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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
           Trie* root=new Trie('-');
           vector<pair<int,pair<int,int>>>offlineQ;
           for(int i=0;i<queries.size();i++){
               offlineQ.push_back({queries[i][1],{queries[i][0],i}});
           }
           vector<int>ans(queries.size(),-1);
           sort(offlineQ.begin(),offlineQ.end());
           sort(nums.begin(),nums.end());
           int j=0;
           for(int i=0;i<nums.size();i++){
               while(j<offlineQ.size()&&offlineQ[j].first<nums[i]){
                   if(i!=0){//all elements arw geater than mj if i==0//dont do anything as we initilized with -1
                      ans[offlineQ[j].second.second]=root->getMax(root,offlineQ[j].second.first); 
                   }
                   j++;
               }
               root->insert(root,nums[i]);
           }
           for(int k=j;k<offlineQ.size();k++){//all elemets in nums may be smaller than mj of query
                   ans[offlineQ[k].second.second]=root->getMax(root,offlineQ[k].second.first); 
           }
           return ans;
    }
};