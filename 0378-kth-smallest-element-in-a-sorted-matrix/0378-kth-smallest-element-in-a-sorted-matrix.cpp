class Solution {
public:
    int find(vector<vector<int>>& matrix, int mid){
        int m=matrix.size();
        int n=matrix[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            auto it=upper_bound(matrix[i].begin(),matrix[i].end(),mid);
            if(it==matrix[i].begin()) break;
            count+=it-matrix[i].begin();
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // priority_queue<int>pq;
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[0].size();j++){
        //         pq.push(matrix[i][j]);
        //         if(pq.size()>k) pq.pop();
        //     }
        // }
        // return pq.top();

        int m=matrix.size();
        int n=matrix[0].size();
        int s=INT_MAX;
        int e=INT_MIN;
        for(int i=0;i<m;i++){
            s=min(s,matrix[i][0]);
            e=max(e,matrix[i][n-1]);
        }
        int ans;
        while(s<=e){
            int mid=s+(e-s)/2;
            int cnt=find(matrix,mid);
            if(cnt>=k){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};