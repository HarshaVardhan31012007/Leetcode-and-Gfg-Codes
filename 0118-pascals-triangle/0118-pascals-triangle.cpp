class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++){
            int c=1;
            vector<int>temp;
            for(int j=0;j<=i;j++){
                temp.push_back(c);
                c=c*(i-j)/(j+1);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};