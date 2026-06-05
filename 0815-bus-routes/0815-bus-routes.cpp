class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n=routes.size();
        if(source==target) return 0;
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<routes[i].size();j++){
                mpp[routes[i][j]].push_back(i);
            }
        }
        queue<int>q;
        vector<int>visited(n,0);
        for(auto &route:mpp[source]){
            q.push(route);
            visited[route]=1;
        }
        int count=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int route=q.front();
                q.pop();
                for(auto &stop:routes[route]){
                    if(stop==target) return count; 
                    for(auto &route:mpp[stop]){
                        if(!visited[route]){
                            q.push(route);
                            visited[route]=1;
                        }
                    }
                }
            }
            count++;
        }
        return -1;
    }
};