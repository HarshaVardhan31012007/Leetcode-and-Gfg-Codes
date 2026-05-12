class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n=tasks.size();
        sort(tasks.begin(),tasks.end(),[](vector<int>&a,vector<int>&b){
            // if((a[1]-a[0])!=(b[1]-b[0])){
                return (a[1]-a[0])>(b[1]-b[0]);
            // } 
            // else if(a[1]!=b[1]){
            //     return a[1]>b[1];
            // }
            // else
            // return a[1]<b[1];
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