class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int mini=INT_MAX;
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        int start=0;
        for(int i=0;i<(int)arr.size()-1;i++){
            int diff=abs(arr[i+1]-arr[i]);
            if(diff<mini){
                mini=diff;
                start=ans.size();
                ans.push_back({arr[i],arr[i+1]});
            }
            else if(diff==mini){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return  vector<vector<int>>(ans.begin()+start,ans.end());
    }
};