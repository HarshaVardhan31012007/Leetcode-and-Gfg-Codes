class Solution {
public:
    string b;
    vector<vector<string>>ans;
    void dfs(string &last,unordered_map<string,int>&distance,vector<string>&temp){
        if(last==b){
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            reverse(temp.begin(),temp.end());
            return;
        }
        string word=last;
        int steps=distance[last];
        for(int i=0;i<word.length();i++){
            char original=word[i];
            for(int j=0;j<26;j++){
                word[i]=j+'a';
                if(distance.count(word)&&distance[word]==(steps-1)){
                    temp.push_back(word);
                    dfs(word,distance,temp);
                    temp.pop_back();
                }
            }
            word[i]=original;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        b=beginWord;
        unordered_set<string>wordList1;
        for(auto &each:wordList)
        wordList1.insert(each);
        queue<string>q;
        unordered_set<string>visited;
        q.push(beginWord);
        visited.insert(beginWord);
        unordered_map<string,int>distance;
        distance[beginWord]=0;
        int m=beginWord.length();
        vector<string>temp;
        while(!q.empty()){
                auto front=q.front();
                q.pop();
                string start=front;
                for(int i=0;i<m;i++){
                    char original=front[i];
                    for(int j=0;j<26;j++){
                        char newchar=j+'a';
                        front[i]=newchar;
                        if(!visited.count(front)&&wordList1.count(front)){
                            visited.insert(front);
                            distance[front]=distance[start]+1;
                            q.push(front);
                        }
                    }
                    front[i]=original;
                }
        }
        if(distance.find(endWord)!=distance.end()){
             vector<string>temp;
             temp.push_back(endWord);
             dfs(endWord,distance,temp);
        }
        return ans;
    }
};