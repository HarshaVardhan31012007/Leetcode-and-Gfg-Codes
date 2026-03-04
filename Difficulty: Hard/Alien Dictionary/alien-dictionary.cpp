class Solution {
  public:
    string findOrder(vector<string> &words) {
        int n=words.size();
        vector<vector<int>>adjList(26);
        vector<int>indegree(26,-1);
        for(auto &each:words){
            for(auto &ch:each){
                if(indegree[ch-'a']==-1)
                indegree[ch-'a']=0;
            }
        }
        string prev=words[0];
        for(int i=1;i<n;i++){
             string curr=words[i];
             bool flag=1;
             for(int j=0;j<min(curr.length(),prev.length());j++){
                 if(curr[j]!=prev[j]){
                     adjList[prev[j]-'a'].push_back(curr[j]-'a');
                     indegree[curr[j]-'a']++;
                     flag=0;
                     break;
                 }
             }
             if(flag&&prev.length()>curr.length()) return "";
             prev=curr;
        }
        queue<int>q;
        int nodes=0;
        for(int i=0;i<26;i++){
            if(indegree[i]==0){
                q.push(i);
            }
            if(indegree[i]!=-1) nodes++;
        }
        string ans="";
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            ans+=(front+'a');
            for(auto &adj:adjList[front]){
                indegree[adj]--;
                if(indegree[adj]==0)
                q.push(adj);
            }
        }
        int n1=ans.length();
        if(n1!=nodes) return "";
        return ans;
    }
};