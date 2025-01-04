class Solution {
public:
    auto findprevsmaller(vector<int>&arr){
        vector<int>prev;
        stack<int>st;
        st.push(-1);
        for(int i=0;i<arr.size();i++){
            int element=arr[i];
            while(st.top()!=-1&&arr[st.top()]>element){//equality hona
               st.pop();
            }
            prev.push_back(st.top());
            st.push(i);
        }
        return prev;
    }
    auto findnextsmaller(vector<int>&arr){
        //vector<int>next(arr.size(),-1);
        vector<int>next;
        stack<int>st;
        st.push(-1);
        for(int i=arr.size()-1;i>=0;i--){
            int element=arr[i];
            while(st.top()!=-1&&arr[st.top()]>=element){//no equality
               st.pop();
            }
            next.push_back(st.top());
            st.push(i);
        }
        return next;
    }
    int sumSubarrayMins(vector<int>& arr) {
        auto prev=findprevsmaller(arr);
        auto next=findnextsmaller(arr);
        //another way
        reverse(next.begin(),next.end());
        long long sum=0;
        const int mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            next[i]=next[i]==-1?arr.size():next[i];
            int plen=i-prev[i];
            int nlen=next[i]-i;
           long long t=((plen%mod)*(nlen%mod))%mod;
           long long ans=(t*arr[i])%mod;
           sum=(sum+ans)%mod;
        }
        return sum;
    }
};
