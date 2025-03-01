class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        unordered_map<string,int>mpp;int m=words[0].length();
        for(int i=0;i<words.size();i++) 
        mpp[words[i]]++;
        for(int i=0;i<m;i++){
            unordered_map<string,int>visited;
            int count=0;
            for(int j=i;j<s.length();j=j+m){
                string str=s.substr(j,m);
                if(mpp.find(str)==mpp.end()){
                    count=0;
                    visited.clear();
                }
                else{
                    count++;
                    visited[str]++;
                    cout<<str<<" "<<visited[str]<<" "<<count<<endl;
                    while(visited[str]>mpp[str]){
                        string temp=s.substr(j-(count-1)*m,m);
                        visited[temp]--;
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