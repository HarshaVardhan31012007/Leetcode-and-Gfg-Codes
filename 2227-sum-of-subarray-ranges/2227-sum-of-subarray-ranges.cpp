class Solution {
public:
    auto findprevsmaller(vector<int>&arr){
        vector<int>prev;
        stack<int>st;
        st.push(-1);
        for(int i=0;i<arr.size();i++){
            int element=arr[i];
            while(st.top()!=-1&&arr[st.top()]>element){//equality hona if next no equality
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
            while(st.top()!=-1&&arr[st.top()]>=element){//no equality if prev has eqaulity
               st.pop();
            }
            next.push_back(st.top());
            st.push(i);
        }
        return next;
    }
    long long int sumSubarrayMins(vector<int>& arr) {
        auto prev=findprevsmaller(arr);
        auto next=findnextsmaller(arr);
        //another way
        reverse(next.begin(),next.end());
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            next[i]=next[i]==-1?arr.size():next[i];
            long int plen=i-prev[i];
            long int nlen=next[i]-i;
           sum=sum+(plen*nlen)*arr[i];
        }
        return sum;
    }
     auto findprevgreater(vector<int>&arr){
        vector<int>prev;
        stack<int>st;
        st.push(-1);
        for(int i=0;i<arr.size();i++){
            int element=arr[i];
            while(st.top()!=-1&&arr[st.top()]<element){//equality hona if next no equality
               st.pop();
            }
            prev.push_back(st.top());
            st.push(i);
        }
        return prev;
    }
    auto findnextgreater(vector<int>&arr){
        //vector<int>next(arr.size(),-1);
        vector<int>next;
        stack<int>st;
        st.push(-1);
        for(int i=arr.size()-1;i>=0;i--){
            int element=arr[i];
            while(st.top()!=-1&&arr[st.top()]<=element){//no equality if prev has eqaulity
               st.pop();
            }
            next.push_back(st.top());
            st.push(i);
        }
        return next;
    }
    long long int sumSubarrayMaxs(vector<int>& arr) {
        auto prev=findprevgreater(arr);
        auto next=findnextgreater(arr);
        //another way
        reverse(next.begin(),next.end());
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            next[i]=next[i]==-1?arr.size():next[i];
            long long int plen=i-prev[i];
            long long int nlen=next[i]-i;
           sum=sum+(plen*nlen)*arr[i];
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long int sum1=sumSubarrayMins(nums);
        long long int sum2=sumSubarrayMaxs(nums);
        return sum2-sum1;
    }
};