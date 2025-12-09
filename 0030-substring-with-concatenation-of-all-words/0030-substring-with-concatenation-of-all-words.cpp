class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
       int n=s.length();
       int m=words[0].length();
       unordered_map<string,int>freq;
       for(auto &word:words){
          freq[word]++;
       }
       vector<int>ans;
        for(int i=0;i<m;i++){
          unordered_map<string,int>visited;
          int count=0;
          for(int j=i;j<n;j=j+m){
              string curr=s.substr(j,m);
              if(freq.find(curr)==freq.end()){
                visited.clear();
                count=0;
              }
              else{
                 visited[curr]++;
                 count++;
                 while(visited[curr]>freq[curr]){
                    string start=s.substr(j-(count-1)*m,m);
                    visited[start]--;
                    count--;
                 }
                 if(count==words.size()){
                    ans.push_back(j-(count-1)*m);
                 }
              }
          }
       }
       return ans;
    }
};