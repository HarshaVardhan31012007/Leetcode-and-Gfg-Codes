class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int i=rowIndex;
        vector<int>temp(1,1);
        long long int c=1;
        for(int j=1;j<=i;j++){
            c=c*(i-j+1)/j;
            temp.push_back(c);
        }
        return temp;
    }
};