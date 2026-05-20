class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans;
        int c=0;
        unordered_set<int>st;
        unordered_set<int>st1;
        for(int i=0;i<A.size();i++){
            if(A[i]==B[i]){
                c++;
            }
            else{
                if(st1.count(A[i])) c++;
                if(st.count(B[i])) c++;
            }
            st.insert(A[i]);
            st1.insert(B[i]);
            ans.push_back(c);
        }
        return ans;
    }
};