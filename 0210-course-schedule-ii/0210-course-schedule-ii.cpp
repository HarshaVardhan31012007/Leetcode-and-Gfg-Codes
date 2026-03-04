class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int>dependents(numCourses,0);
        vector<vector<int>>adjCourses(numCourses);
        for(auto &each:prerequisites){
            int u=each[0];int v=each[1];
            adjCourses[v].push_back(u);
            dependents[u]++;
        }
        queue<int>q;
        for(int course=0;course<numCourses;course++){
            if(dependents[course]==0)
            q.push(course);
        }
        vector<int>ans;
        while(!q.empty()){
            auto current=q.front();
            q.pop();
            ans.push_back(current);
            for(auto &adj:adjCourses[current]){
                 dependents[adj]--;
                 if(dependents[adj]==0)
                 q.push(adj);
            }
        }
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};