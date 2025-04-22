class Solution {
public:
    void bfs(unordered_map<string,list<string>>&adjList,unordered_map<string,bool>&visited,unordered_map<string,string>&parent,string &s){
        queue<string>q;
        q.push(s);
        visited[s]=1;
        parent[s]="\0";
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            for(auto &nbr:adjList[front]){
                if(!visited[nbr]){
                    visited[nbr]=1;
                    parent[nbr]=front;
                    q.push(nbr);
                }
            }
        }
    }
    bool check(string &a,string &b){
        int count=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                count++;
            }
        }
        return count==1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,list<string>>adjList;
        bool flag=0;bool flag1=0;
        for(int i=0;i<wordList.size();i++){
            if(wordList[i]==endWord)
            flag=1;
            if(wordList[i]==beginWord)
            flag1=1;
        }
        if(!flag) return 0;
        if(!flag1)
        wordList.push_back(beginWord);
        for(int i=0;i<wordList.size();i++){
            string word=wordList[i];
            for(int j=0;j<wordList.size();j++){
                string word1=wordList[j];
                if(word!=word1){
                    if(check(word,word1)){
                        adjList[word].push_back(word1);
                        adjList[word1].push_back(word);
                    }
                }
            }
        }
       unordered_map<string,bool>visited;
       unordered_map<string,string>parent;
       bfs(adjList,visited,parent,beginWord);
       string node=endWord;
       int count=0;
       while(node!="\0"){
        if(node==beginWord||parent[node]!="\0")
        count++;
        node=parent[node];
       }
       return count;
    }
};