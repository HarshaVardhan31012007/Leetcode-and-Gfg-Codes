class Solution {
public:
    void topoSort(unordered_map<int,list<int>>&adjList,vector<int>&ans,vector<int>&indegree){
        queue<int>q;
        for(int j=0;j<indegree.size();j++){
            if(indegree[j]==0)
            q.push(j);
        }
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto &nbr:adjList[front]){
                indegree[nbr]--;
                if(indegree[nbr]==0)
                q.push(nbr);
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        unordered_map<int,list<int>>adjList;
        vector<int>indegree(n,0);
        for(int i=0;i<prerequisites.size();i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        vector<int>ans;
        topoSort(adjList,ans,indegree);
        vector<int>temp;
        return (ans.size()==n)?ans:temp;
    }
};