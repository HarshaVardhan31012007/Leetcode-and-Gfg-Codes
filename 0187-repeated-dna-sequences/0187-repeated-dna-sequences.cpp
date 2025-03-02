class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        unordered_map<string,int>visited;
        for(int i=0;i<10;i++){
            for(int j=i;j<s.length();j=j+10){
               string temp=s.substr(j,10);
               visited[temp]++;
               if(visited[temp]>1){
                 ans.push_back(temp);
                 visited[temp]=INT_MIN;
               }
            }
        }
        return ans;
    }
};