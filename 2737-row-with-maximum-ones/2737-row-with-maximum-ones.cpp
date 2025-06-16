class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int ans=0;int maxi=INT_MIN;
        for(int i=0;i<mat.size();i++){
            int count=0;
           for(int j=0;j<mat[i].size();j++){
            if(mat[i][j])
            count++;
           }
           if(count>maxi){
            maxi=count;
            ans=i;
           }
        }
        return {ans,maxi};
    }
};