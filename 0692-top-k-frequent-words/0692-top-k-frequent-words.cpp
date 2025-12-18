class Solution {
public:
    // class comp{
    //     public:
    //     bool operator()(pair<int,string>&a,pair<int,string>&b){
    //         if(a.first!=b.first)
    //         return a.first>b.first;
    //         return a.second<b.second;
    //     }
    // };
    // vector<string> topKFrequent(vector<string>& words, int k) {
    //     unordered_map<string,int>freq;
    //     for(auto &each:words){
    //         freq[each]++;
    //     }
    //     priority_queue<pair<int,string>,vector<pair<int,string>>,comp>pq;
    //     for(auto &each:freq){
    //         pq.push({each.second,each.first});
    //         if(pq.size()>k)
    //         pq.pop();
    //     }
    //     // vector<string>ans;
    //     // while(!pq.empty()){
    //     //     ans.push_back(pq.top().second);
    //     //     pq.pop();
    //     // }
    //     // sort(ans.begin(),ans.end(),[&](string &a,string &b){
    //     //     if(freq[a]!=freq[b])
    //     //     return freq[a]>freq[b];
    //     //     return a<b;
    //     // });


    //     vector<string>ans(pq.size());
    //     int i=pq.size()-1;
    //     while(!pq.empty()){
    //         ans[i--]=pq.top().second;
    //         pq.pop();
    //     }
    //     return ans;
    // }


     class Trie{
        public:

        char data;
        Trie* children[26];
        bool isterminal;
        int freq;
        
        Trie(char val){
            this->data=val;
            this->isterminal=false;
            this->freq=0;
            for(int i=0;i<26;i++){
                this->children[i]=NULL;
            }
        } 

        void insertHelp(Trie* root,string word,int i){
            if(i>=word.length()){
                root->isterminal=true;
                root->freq++;
                return;
            }
            if(root->children[word[i]-'a']==NULL)
            root->children[word[i]-'a']=new Trie(word[i]);
            insertHelp(root->children[word[i]-'a'],word,i+1);
        }
     };
     class comp{
        public:
        bool operator()(pair<int,string>&a,pair<int,string>&b){
            return (a.first==b.first?a<b:a>b);
            // return (a.first==b.first?a<b:a.first>b.first);
            // return (a.first==b.first?a.second<b.second:a>b);
        }
     };
     void traverse(Trie* root,priority_queue<pair<int,string>,vector<pair<int,string>>,comp>&pq,string &s,int k){
        if(root->isterminal){
            if(pq.size()<k)
            pq.push({root->freq,s});
            else if(pq.size()==k&&root->freq>pq.top().first){
                pq.pop();
                pq.push({root->freq,s});
            }
        }
        for(int i=0;i<26;i++){
             if(root->children[i]){
                s.push_back(i+'a');
                traverse(root->children[i],pq,s,k);
                s.pop_back();
             }
        }
     }
    vector<string> topKFrequent(vector<string>& words, int k) {

        Trie* root=new Trie('-');

        for(auto &each:words){
            root->insertHelp(root,each,0);
        }

        priority_queue<pair<int,string>,vector<pair<int,string>>,comp>pq;
        string s="";
        traverse(root,pq,s,k);
        vector<string>ans(pq.size());
        int i=pq.size()-1;
        while(!pq.empty()){
            ans[i--]=pq.top().second;
            pq.pop();
        }
        return ans;
    }

};