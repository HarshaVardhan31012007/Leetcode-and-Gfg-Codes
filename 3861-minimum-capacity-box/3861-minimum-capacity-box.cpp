class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n=capacity.size();
        int mini=INT_MAX;
        int minIndex=-1;
        for(int i=0;i<n;i++){
            if(capacity[i]>=itemSize&&capacity[i]<mini){
                mini=capacity[i];minIndex=i;
            }
        }
        return minIndex;
    }
};