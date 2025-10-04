class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        int n=numRows;
        for(int i=0;i<n;i++){
            vector<int>temp(1,1);
            int c=1;
            for(int j=1;j<=i;j++){
                c=c*(i-j+1)/j;
                temp.push_back(c);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};