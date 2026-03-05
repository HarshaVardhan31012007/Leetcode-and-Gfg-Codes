class Solution {
public:
    // int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    //     unordered_set<string>wordList1;
    //     for(auto &each:wordList)
    //     wordList1.insert(each);
    //     queue<string>q;
    //     unordered_set<string>visited;
    //     q.push(beginWord);
    //     visited.insert(beginWord);
    //     unordered_map<string,int>distance;
    //     distance[beginWord]=1;
    //     int m=beginWord.length();
    //     while(!q.empty()){
    //         auto front=q.front();
    //         q.pop();
    //         if(front==endWord) return distance[front];
    //         string start=front;
    //         for(int i=0;i<m;i++){
    //             char original=front[i];
    //             for(int j=0;j<26;j++){
    //                 char newchar=j+'a';
    //                 front[i]=newchar;
    //                 if(!visited.count(front)&&wordList1.count(front)){
    //                     visited.insert(front);
    //                     q.push(front);
    //                     distance[front]=distance[start]+1;
    //                 }
    //             }
    //             front[i]=original;
    //         } 
    //     }
    //     return 0;
    // }


    // int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    //     unordered_set<string>wordList1;
    //     for(auto &each:wordList)
    //     wordList1.insert(each);
    //     queue<string>q;
    //     unordered_set<string>visited;
    //     q.push(beginWord);
    //     visited.insert(beginWord);
    //     int dist=1;
    //     int m=beginWord.length();
    //     while(!q.empty()){
    //         int size=q.size();
    //         while(size--){
    //             auto front=q.front();
    //             q.pop();
    //             if(front==endWord) return dist;
    //             string start=front;
    //             for(int i=0;i<m;i++){
    //                 char original=front[i];
    //                 for(int j=0;j<26;j++){
    //                     char newchar=j+'a';
    //                     front[i]=newchar;
    //                     if(!visited.count(front)&&wordList1.count(front)){
    //                         visited.insert(front);
    //                         q.push(front);
    //                     }
    //                 }
    //                 front[i]=original;
    //             } 
    //         }
    //         dist++;
    //     }
    //     return 0;
    // }



    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wordList1;
        for(auto &each:wordList)
        wordList1.insert(each);
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        int m=beginWord.length();
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto front=q.front().first;
                auto dist=q.front().second;
                q.pop();
                if(front==endWord) return dist;
                string start=front;
                for(int i=0;i<m;i++){
                    char original=front[i];
                    for(int j=0;j<26;j++){
                        char newchar=j+'a';
                        front[i]=newchar;
                        if(wordList1.count(front)){
                            wordList1.erase(front);
                            q.push({front,dist+1});
                        }
                    }
                    front[i]=original;
                } 
            }
        }
        return 0;
    }
};