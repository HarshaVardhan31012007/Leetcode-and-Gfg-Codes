class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>dependents(numCourses,0);
        vector<vector<int>>adjCourses(numCourses);
        for(auto &each:prerequisites){
            int u=each[0];int v=each[1];
            adjCourses[u].push_back(v);
            dependents[v]++;
        }
        queue<int>q;
        for(int course=0;course<numCourses;course++){
            if(dependents[course]==0)
            q.push(course);
        }
        int completed=0;
        while(!q.empty()){
            auto current=q.front();
            q.pop();
            completed++;
            for(auto &adj:adjCourses[current]){
                 dependents[adj]--;
                 if(dependents[adj]==0)
                 q.push(adj);
            }
        }
        return completed==numCourses;
    }
};