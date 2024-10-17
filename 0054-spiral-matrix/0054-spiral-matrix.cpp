class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        vector<int>ans;
        int m= arr.size();
        int n= arr[0].size();
        int p = m*n;

        int i1 = 0;
        int j2 = n-1;
        int j1 = 0;
        int i2 = m-1;

        
        int count=0;
        while(count<p){
    
        for(int j=j1;j<=j2&&count<p;j++){
        ans.push_back(arr[i1][j]);
        count++;
        }

        i1++;
        
        for(int i=i1;i<=i2&&count<p;i++){
        ans.push_back(arr[i][j2]);
        count++;
        }
        j2--;

        for(int j=j2;j>=j1&&count<p;j--){
        ans.push_back(arr[i2][j]);
        count++;
        }
        i2--;

        for(int i=i2;i>=i1&&count<p;i--){
        ans.push_back(arr[i][j1]);
        count++;
        }
        j1++;


        }

     return ans;

    }
};