class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        auto it=max_element(arr.begin(),arr.end());
        int ans=*it;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==ans)
            return i;
        }
        return -1;
    }
};