class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int>st(arr.begin(),arr.end());
        for(int i=1;i<=2000;i++){
            if(!st.count(i))
            k--;
            if(k==0) return i;
        }
        return -1;
    }
};