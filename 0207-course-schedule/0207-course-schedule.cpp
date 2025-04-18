class Solution {
public:
   //Valid topological sort means no cycle hence we should check cycle present or not

   //By BFS

    void topoSort(vector<vector<int>>& prerequisites,vector<int>&ans,int n){
        vector<int>indegree(n);
        queue<int>q;
        for(auto &each:prerequisites){
            indegree[each[0]]++; 
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            auto front=q.front();
            ans.push_back(front);
            q.pop();
            for(auto &each:prerequisites){
                int k;
                if(each[1]==front) k=each[0];
                else continue;
                indegree[k]--;
                if(indegree[k]==0)
                q.push(k);
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        int n=numCourses;
        topoSort(prerequisites,ans,n);
        if(ans.size()==n)
        return true;
        return false;
    }


//by DFS


//    bool checkCycle(vector<vector<int>>& prerequisites,unordered_map<int,bool>&visited,unordered_map<int,bool>&path,int s){
//     visited[s]=1;path[s]=1;
//     for(auto &each:prerequisites){
//         int k;
//         if(each[1]==s) k=each[0];
//         else continue;
//         if(!visited[k]){
//             bool ans=checkCycle(prerequisites,visited,path,k);
//             if(ans==true)
//             return true;
//         }
//         else if(visited[k]==true&&path[k]==true){
//             return true;
//         }
//     }
//     path[s]=false;
//     return false;
//    }
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         unordered_map<int,bool>visited;
//         unordered_map<int,bool>path;
//         int n=numCourses;
//         bool ans=0;
//         for(int i=0;i<n;i++){
//             if(!visited[i]){
//                 ans=checkCycle(prerequisites,visited,path,i);
//                 if(ans==true){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
};