class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n=tasks.size();
        for(int i=0;i<n;i++){
            tasks[i].push_back(tasks[i][1]-tasks[i][0]);
        }
        sort(tasks.begin(),tasks.end(),[](vector<int>&a,vector<int>&b){
            if(a[2]!=b[2]){
                return a[2]>b[2];
            } 
            else if(a[1]!=b[1]){
                return a[1]>b[1];
            }
            else
            return a[1]<b[1];
        });
        int ans=tasks[0][1];
        int temp=ans;
        for(int i=0;i<n;i++){ 
            if(temp>=tasks[i][1]){
                temp-=tasks[i][0];
            }
            else{
                int diff=tasks[i][1]-temp;
                ans+=diff;
                temp+=diff;
                temp-=tasks[i][0];
            }
        }
        return ans;
    }
};