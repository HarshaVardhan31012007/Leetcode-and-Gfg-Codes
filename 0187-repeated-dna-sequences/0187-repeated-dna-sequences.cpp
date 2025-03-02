class Solution {
public:
    // vector<string> findRepeatedDnaSequences(string s) {
    //     vector<string>ans;
    //     unordered_map<string,int>visited;
    //     for(int i=0;i<10;i++){
    //         for(int j=0;j<s.length()-9;j++){
    //            string temp=s.substr(j,10);
    //            visited[temp]++;
    //            if(visited[temp]>1){
    //              ans.push_back(temp);
    //              visited[temp]=INT_MIN;
    //            }
    //         }
    //     }
    //     return ans;
    // }

    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        unordered_map<string,int>visited;
            for(int j=0;j<s.length();j++){
               string temp=s.substr(j,10);
               visited[temp]++;
               if(visited[temp]>1){
                 ans.push_back(temp);
                 visited[temp]=INT_MIN;
               }
            }
        return ans;
    }
};