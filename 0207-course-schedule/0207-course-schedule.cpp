class Solution {
public:
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
    // }

   bool checkCycle(vector<vector<int>>& prerequisites,unordered_map<int,bool>&visited,unordered_map<int,bool>&path,int s){
    visited[s]=1;path[s]=1;
    for(auto &each:prerequisites){
        int k;
        if(each[1]==s) k=each[0];
        else continue;
        if(!visited[k]){
            bool ans=checkCycle(prerequisites,visited,path,k);
            if(ans==true)
            return true;
        }
        else if(visited[k]==true&&path[k]==true){
            return true;
        }
    }
    path[s]=false;
    return false;
   }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,bool>visited;
        unordered_map<int,bool>path;
        int n=numCourses;
        bool ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans=checkCycle(prerequisites,visited,path,i);
                if(ans==true){
                    return false;
                }
            }
        }
        return true;
    }
};