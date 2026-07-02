class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>sortedArr=arr;
        sort(sortedArr.begin(),sortedArr.end());
        unordered_map<int,int>rank;
        int prev=INT_MIN;
        int r=1;
        for(int i=0;i<sortedArr.size();i++){
            if(prev!=sortedArr[i]){
                rank[sortedArr[i]]=r++;
                prev=sortedArr[i];
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=rank[arr[i]];
        }
        return arr;
    }
};