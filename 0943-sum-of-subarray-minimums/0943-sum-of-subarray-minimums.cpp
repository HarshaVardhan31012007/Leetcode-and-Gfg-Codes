class Solution {
public:
    void nextSmaller(vector<int>&arr,vector<int>&nexts){
        stack<int>s;
        s.push(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(s.top()!=arr.size()&&arr[s.top()]>arr[i]){
                s.pop();
            }
            nexts.push_back(s.top());
            s.push(i);
        } 
    }
    void prevSmaller(vector<int>&arr,vector<int>&prevs){
        stack<int>s;
        s.push(-1);
        for(int i=0;i<arr.size();i++){
        while(s.top()!=-1&&arr[s.top()]>=arr[i]){
            s.pop();
        }
        prevs.push_back(s.top());
        s.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
       vector<int>nexts;
       int mod=1e9+7;
       nextSmaller(arr,nexts);
       reverse(nexts.begin(),nexts.end());
       vector<int>prevs;
       prevSmaller(arr,prevs);
       long long int sum=0;
       for(int i=0;i<arr.size();i++){
        int leftl=i-prevs[i];
        int rightl=nexts[i]-i;
        long long int p=(leftl*rightl)%mod;
        p=(arr[i]*p)%mod;
        sum=(sum+p)%mod;
       }
       return sum%mod;
    }
};