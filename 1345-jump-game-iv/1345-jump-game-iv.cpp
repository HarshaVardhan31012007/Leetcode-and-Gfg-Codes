class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        vector<int>visited(n,0);
        visited[0]=1;
        int steps=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int idx=q.front();
                q.pop();
                if(idx==(n-1)) return steps;
                if(idx+1<n&&!visited[idx+1]){
                    q.push(idx+1);
                    visited[idx+1]=1;
                }
                if(idx>0&&!visited[idx-1]){
                    q.push(idx-1);
                    visited[idx-1]=1;
                }
                if(!mpp.count(arr[idx])) continue;
                for(auto &index:mpp[arr[idx]]){
                    if(!visited[index]){
                        q.push(index);
                        visited[index]=1;
                    }
                }
                mpp[arr[idx]].clear();
                mpp.erase(arr[idx]);
            }
            steps++;
        }
        return -1;
    }
};