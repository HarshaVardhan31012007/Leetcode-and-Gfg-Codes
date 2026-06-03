class Solution {
public:
    int maxDepth(string s) {
        // int c=0;
        // int maxi=0;
        // for(int i=0;i<s.length();i++){
        //     if(s[i]=='(') c++;
        //     else if(s[i]==')') c--;
        //     maxi=max(maxi,c);
        // }
        // return maxi;



        stack<int>st;
        int maxi=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push('(');
            else if(s[i]==')'){
                st.pop();
            }
            maxi=max(maxi,(int)st.size());
        }
        return maxi;
    }
};