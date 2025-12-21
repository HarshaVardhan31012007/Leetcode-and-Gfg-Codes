class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<int>ans;
        int prev=-1;
        vector<int>visited(strs.size(),-1);
        for(int i=0;i<strs[0].size();i++){
            int flag=2;
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]>strs[j-1][i]){
                    if(visited[j]==-1)
                    visited[j]=i;
                    continue;
                }
                else if(strs[j][i]==strs[j-1][i]){
                    flag=1;
                    continue;
                }
                else if(visited[j]!=-1){
                    continue;
                }
                flag=0;
                break;
            }
            if(flag==0){
              ans.push_back(i);
              for(auto &each:visited){
                  if(each==i)
                  each=-1;
              }
            }
            else if(flag==1){
                prev=i;
            }
            else if(flag==2){
                return ans.size();
            }
        }
        return ans.size();
    }
};