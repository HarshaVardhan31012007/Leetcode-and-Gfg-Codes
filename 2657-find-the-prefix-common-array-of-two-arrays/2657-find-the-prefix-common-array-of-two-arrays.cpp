class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        // vector<int>ans;
        // int c=0;
        // unordered_set<int>st;
        // unordered_set<int>st1;
        // for(int i=0;i<A.size();i++){
        //     if(A[i]==B[i]){
        //         c++;
        //     }
        //     else{
        //         if(st1.count(A[i])) c++;
        //         if(st.count(B[i])) c++;
        //     }
        //     st.insert(A[i]);
        //     st1.insert(B[i]);
        //     ans.push_back(c);
        // }
        // return ans;


        // int n=A.size();
        // vector<int>ans;
        // vector<pair<int,int>>visited(n,{0,0});
        // int c=0;
        // for(int i=0;i<A.size();i++){
        //     if(A[i]==B[i]){
        //         c++;
        //     }
        //     else{
        //         if(visited[A[i]-1].second==1) c++;
        //         if(visited[B[i]-1].first==1) c++;
        //     }
        //     visited[A[i]-1].first=1;
        //     visited[B[i]-1].second=1;
        //     ans.push_back(c);
        // }
        // return ans;


        // int n=A.size();
        // vector<int>ans;
        // vector<int>freq(n,0);
        // int c=0;
        // for(int i=0;i<A.size();i++){
        //     freq[A[i]-1]++;
        //     freq[B[i]-1]++;
        //     if(freq[A[i]-1]==2){
        //         c++;
        //     }
        //     if(A[i]!=B[i]&&freq[B[i]-1]==2){
        //         c++;
        //     }
        //     ans.push_back(c);
        // }
        //return ans;


        // vector<int>ans;
        // int c=0;
        // unordered_set<int>st;
        // for(int i=0;i<A.size();i++){
        //     if(A[i]==B[i]){
        //         c++;
        //     }
        //     else{
        //         if(st.count(A[i])) c++;
        //         if(st.count(B[i])) c++;
        //     }
        //     st.insert(A[i]);
        //     st.insert(B[i]);
        //     ans.push_back(c);
        // }
        // return ans;

        // int n=A.size();
        // vector<int>ans;
        // vector<int>freq(n+1,0);
        // int c=0;
        // for(int i=0;i<A.size();i++){
        //     if(++freq[A[i]]==2) c++;
        //     if(++freq[B[i]]==2) c++;
        //     ans.push_back(c);
        // }
        // return ans;



        int n=A.size();
        vector<int>ans;
        vector<int>seen(51,0);
        int mask=0;
        int c=0;
        for(int i=0;i<A.size();i++){
            if(A[i]==B[i]) c++;
            else{
                if(seen[A[i]]) c++;
                if(seen[B[i]]) c++;
            }
            seen[A[i]]=1;
            seen[B[i]]=1;
            ans.push_back(c);
        }
        return ans;
    }
};